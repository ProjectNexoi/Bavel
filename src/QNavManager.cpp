#include "Header.hpp"
#include <nlohmann/json.hpp> 
#include "ftxui/component/component.hpp"


namespace QNavManager{
    void ReloadQNavButtons(ftxui::Components& qNavButtons, std::vector<std::string>& qNavPaths, std::vector<ListItem*>& currentContent, std::vector<std::string>& currentStringified, std::string& currentPath, std::string& exception, SortTypes& sortType){
        qNavButtons.clear();
        for(int i = 0; i < qNavPaths.size(); i++){
            qNavButtons.push_back(ftxui::Button(&qNavPaths[i], [&, i]{ProcessingFuncs::OnSelectedQNavButton(currentContent, currentStringified, qNavPaths[i], currentPath, exception, sortType);}));
            exception = qNavPaths[i];
        }
    }
}