#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>
#include <vector>
#include "ftxui/component/screen_interactive.hpp"

// Declarations

enum ItemTypes{
    DIR = 0,
    FIL = 1,
    BACK = 2
};

class ListItem{
    private:
        ItemTypes type;
        std::string name;
        std::string lastOpened;
    
    public:
        ListItem(ItemTypes t, std::string n, std::string l);
        ListItem(ItemTypes type, std::string name);
        void SetType(ItemTypes t);
        ItemTypes GetType();
        void SetName(std::string n);
        std::string GetName();
        void SetLastOpened(std::string l);
        std::string GetLastOpened();
        std::string ToString();

};

void PathToItemList(std::string path, std::vector<ListItem*>& currentContent);

namespace ProcessingFuncs{
    void StringifyContent(std::vector<ListItem*>& currentContent, 
        std::vector<std::string>& currentStringified);
    void OnSelectedMenuOption(
        std::vector<ListItem*>& currentContent, 
        std::vector<std::string>& currentStringified,
        std::string& currentPath,
        int& selected,
        std::string& exception);
}
#endif 