#include <iostream>
#include <string>
#include <ctime>
#include "Header.hpp"
#include <sys/stat.h>
#include <pwd.h>
#include <filesystem>
namespace fs = std::filesystem;

ListItem::ListItem(ItemTypes t, std::string p, std::filesystem::file_time_type l){
    this->type = t;
    this->path = p;
    this->fileName = p.substr(p.find_last_of("/")+1);
    this->lastOpened = l;
}

ListItem::ListItem(ItemTypes type, std::string path){
    this->type = type;
    this->path = path;
    this->fileName = path.substr(path.find_last_of("/")+1);
}

ListItem::ListItem(std::string path){
    this->path = path;
    this->fileName = path.substr(path.find_last_of("/")+1);
    this->type = std::filesystem::is_directory(path) ? ItemTypes::DIR : ItemTypes::FIL;
    try{this->lastOpened = fs::last_write_time(path);} catch(fs::filesystem_error &e){}
    try{
        if(this->type == ItemTypes::FIL){
            this->size = fs::file_size(path);
        }
        else if (this->type == ItemTypes::DIR){
            //TODO: Implement me!
        }
    } catch(fs::filesystem_error &e){}
    try{
        //struct stat info;
        //stat(path.c_str(), &info);
        //struct passwd *pw = getpwuid(info.st_uid);
        //this->owner = pw->pw_name;
    }catch(fs::filesystem_error &e){}

}

void ListItem::SetType(ItemTypes t){
    this->type = t;
}

ItemTypes ListItem::GetType(){
    return this->type;
}

void ListItem::SetPath(std::string p){
    this->path = p;
    this->fileName = p.substr(p.find_last_of("/")+1);
}

std::string ListItem::GetPath(){
    return this->path;
}

std::string ListItem::GetFileName(){
    return this->fileName;
}

void ListItem::SetFileName(std::string fn){
    this->fileName = fn;
}

void ListItem::SetLastOpened(std::filesystem::file_time_type l){
    this->lastOpened = l;
}

std::filesystem::file_time_type ListItem::GetLastOpened(){
    return this->lastOpened;
}

void ListItem::SetSize(uintmax_t s){
    this->size = s;
}

uintmax_t ListItem::GetSize(){
    return this->size;
}

void ListItem::SetOwner(std::string o){
    this->owner = o;
}

std::string ListItem::GetOwner(){
    return this->owner;
}

std::string ListItem::ToString(){
    std::string typeArr[3] = {"DIR", "FIL",""};
    return typeArr[this->type] 
    + "   "
    + (this->type == 2 ? "" : ProcessingFuncs::FsTimeToString(this->lastOpened)) 
    + "   " 
    + this->fileName;
}
