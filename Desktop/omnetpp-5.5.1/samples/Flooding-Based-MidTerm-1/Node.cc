/*
 * Node.cc
 *
 *  Created on: Apr 24, 2020
 *      Author: oguzhan
 */
#include <string.h>
#include <omnetpp.h>

#define ROOT_NODE 2

using namespace omnetpp;

class Node : public cSimpleModule
{
    std::string parent_name;
    std::vector< int > child;
    std::vector< int > other;
    int parent;
    cMessage *msgProbe = new cMessage("probe", 1);
    cMessage *msgAck = new cMessage("acknowledge", 1);//ack mesajını kısa halini kabul etmiyor.
    cMessage *msgReject = new cMessage("reject", 1);

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
};

Define_Module(Node);

void Node::initialize()
{
    parent_name = "";
    EV << this-> gateCount()<<" TH "<<this->getId()<<"\n";
    parent = -1;

    if (this->getId() == ROOT_NODE)
    {
        this->parent = ROOT_NODE;

    for(int i = 0; i < this->gateCount() / 2; i++)
        {   //Başlangıçta bütün komşularına probe mesajı gönderiyoruz.
            send(this->msgProbe->dup(), "gate$o", i);
        }
    }
}

void Node::handleMessage(cMessage *msg)
{
    cGate *arrival_gate = msg->getArrivalGate();//mesajı gönderen node un gate i

    if((int)(child.size()) + (int)(other.size()) != (this->gateCount()/2))
    {
        if(strcmp(msg->getName(), "probe") == 0)
        {
            if(this->parent == -1)//probe mesajı gelen node un parent node u yoksa
            {
                this->parent = arrival_gate->getIndex();//node a parent node index ini atıyoruz.
                this->parent_name = msg->getArrivalGate()->getPreviousGate()->getOwner()->getFullName();//node a parent node name ni atıyoruz.
                send(this->msgAck->dup(),"gate$o",arrival_gate->getIndex());//probe mesajı gelen node a ack mesajı gönderiyoruz.
                for(int i=0; i<this->gateCount()/2;i++)
                {   //probe mesajı alan node komşularına probe mesajı gönderiyor.
                    send(this->msgProbe->dup(),"gate$o",i);
                }
            }
            else//probe mesajı gelen node un parent node u varsa
            {   //probe mesajı gelen node a reject mesajı gönderiyoruz.
                send(this->msgReject->dup(), "gate$o", arrival_gate->getIndex());
            }
        }
        if(strcmp(msg->getName(),"acknowledge") == 0)
        {
            this->child.push_back(0);//ack mesajı alan node child a ekleme yapıyor.
        }
        if(strcmp(msg->getName(),"reject") == 0)
        {
            this->other.push_back(0);//reject mesajı alan node other a ekleme yapıyor.
        }
    }
    else
    {
        this->finish();
    }
}

void Node::finish()
{
    EV << "FINISH: " << this->getFullName() <<  ",Parent :" << parent_name << "\n";
}

