//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

//
// TODO auto-generated type
//
simple Node
{
    parameters:
        @display("i=abstract/router");
    gates:
        inout gate[];
}
network fbmtN
{
        parameters:
        int nodeCount = 14;
        @display("bgb=2205.5337,743.2512");

    submodules:
        node: Node {
            @display("p=81,59;i=abstract/router");
        }
        node1: Node {
            @display("p=385,65;i=abstract/router");
        }
        node2: Node {
            @display("p=684,71;i=abstract/router");
        }
        node3: Node {
            @display("p=86,239;i=abstract/router");
        }
        node4: Node {
            @display("p=385,245;i=abstract/router");
        }
        node5: Node {
            @display("p=691,239;i=abstract/router");
        }
    connections:

        node.gate++ <--> {  delay = 400ms; } <--> node4.gate++;
        node4.gate++ <--> {  delay = 400ms; } <--> node.gate++;
        node.gate++ <--> {  delay = 100ms; } <--> node1.gate++;
        node1.gate++ <--> {  delay = 100ms; } <--> node.gate++;
        node1.gate++ <--> {  delay = 100ms; } <--> node2.gate++;
        node2.gate++ <--> {  delay = 100ms; } <--> node1.gate++;
        node.gate++ <--> {  delay = 100ms; } <--> node3.gate++;
        node3.gate++ <--> {  delay = 100ms; } <--> node.gate++;
        node3.gate++ <--> {  delay = 100ms; } <--> node4.gate++;
        node4.gate++ <--> {  delay = 100ms; } <--> node3.gate++;
        node4.gate++ <--> {  delay = 100ms; } <--> node1.gate++;
        node1.gate++ <--> {  delay = 100ms; } <--> node4.gate++;
        node4.gate++ <--> {  delay = 100ms; } <--> node5.gate++;
        node5.gate++ <--> {  delay = 100ms; } <--> node4.gate++;
        node5.gate++ <--> {  delay = 100ms; } <--> node2.gate++;
        node2.gate++ <--> {  delay = 100ms; } <--> node5.gate++;
        node1.gate++ <--> {  delay = 200ms; } <--> node5.gate++;
        node5.gate++ <--> {  delay = 200ms; } <--> node1.gate++;
}
