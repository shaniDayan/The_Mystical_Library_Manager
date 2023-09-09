#include "containerDoc.h"

void containerDoc::addDocument(const MysticalDocument &other) {
    if(dynamic_cast<const Scroll*>(&other)){
        documents.push_back(std::make_shared<Scroll>(other));
    }
    if(dynamic_cast<const Tome*>(&other)){
        documents.push_back(std::make_shared<Tome>(other));
    }
}

void containerDoc::removeDocumentByName(const string &nameDoc) {
    for(auto it = documents.begin();it!=documents.end();++it){
        if((*it)->getName()==nameDoc){
            documents.erase(it);
        }
    }
}
bool containerDoc::compareByPowerDesc(const std::shared_ptr<MysticalDocument>& a, const std::shared_ptr<MysticalDocument>& b) {
    return a->getPower() > b->getPower();
}
void containerDoc::sortByPower() {
    sort(documents.begin(),documents.end(),compareByPowerDesc);
}

void containerDoc::printAll() {
    for(auto & document : documents){
        cout<<*document;
    }
}

void containerDoc::saveToFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }
    for(const auto& it:documents){
        if (auto tomePtr = dynamic_pointer_cast<Tome>(it)) {
            outFile<<"Tome ";
        }
        if (auto tomePtr = dynamic_pointer_cast<Scroll>(it)) {
            outFile<<"Scroll ";
        }
        outFile<<it->getName()<<" "<<it->getSummary()<<
        " "<<it->getContent() <<" "<<it->getNumPages() <<" " << it->getPower()<<endl;
    }
    outFile.close();
}

void containerDoc::loadFromFile(const string &filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    string line;
    while(getline(inFile,line)){
        istringstream iss(line);
        vector<std::string> tokens;
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        if(tokens.front()=="Tome"){
            Tome temp(tokens[1],tokens[2],tokens[3],tokens[4]);
            addDocument(temp);
        }
        if(tokens.front()=="Scroll"){
            Scroll temp(tokens[1],tokens[2],tokens[3],tokens[4]);
            addDocument(temp);
        }

    }

g }
