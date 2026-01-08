#include <iostream>
#include <string>
#include <ctime>
#include "Header.hpp"


ListItem::ListItem(ItemTypes t, std::string n, std::string l){
    this->type = t;
    this->name = n;
    this->lastOpened = l;
}

ListItem::ListItem(ItemTypes type, std::string name){
    this->type = type;
    this->name = name;
}

void ListItem::SetType(ItemTypes t){
    this->type = t;
}

ItemTypes ListItem::GetType(){
    return this->type;
}

void ListItem::SetName(std::string n){
    this->name = n;
}

std::string ListItem::GetName(){
    return this->name;
}

void ListItem::SetLastOpened(std::string l){
    this->lastOpened = l;
}

std::string ListItem::GetLastOpened(){
    return this->lastOpened;
}

std::string ListItem::ToString(){
    std::string typeArr[3] = {"DIR", "FIL",""};
    return typeArr[this->type] + "   " + this->lastOpened + "   " + this->name;
}
