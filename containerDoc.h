#ifndef THE_MYSTICAL_LIBRARY_MANAGER_CONTAINERDOC_H
#define THE_MYSTICAL_LIBRARY_MANAGER_CONTAINERDOC_H

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "MysticalDocument.h"

using namespace std;
class containerDoc {
public:
    containerDoc()= default;
    void addDocument(const MysticalDocument& other);
    void removeDocumentByName(const string& nameDoc);
    void sortByPower();
    void printAll();
    static  bool compareByPowerDesc(const std::shared_ptr<MysticalDocument>& a,
                                    const std::shared_ptr<MysticalDocument>& b);
    void loadFromFile(const string& filename);
    void saveToFile(const string &filename);
private:
    vector<shared_ptr<MysticalDocument>>documents;
};




#endif //THE_MYSTICAL_LIBRARY_MANAGER_CONTAINERDOC_H
