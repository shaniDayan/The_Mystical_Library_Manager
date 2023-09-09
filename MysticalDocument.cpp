
#include "MysticalDocument.h"

string MysticalDocument::getName() const {
    return m_documentName;
}

ostream &operator<<(ostream &os, const MysticalDocument &m) {
    m.print(os);
    return os;
}

bool MysticalDocument::operator<(const MysticalDocument &other) const{
    return (m_mysticalPower<other.getPower());
}

bool MysticalDocument::operator>(const MysticalDocument &other) const {
    return !(*this<other);
}

bool MysticalDocument::operator==(const MysticalDocument &other) const {
    return (m_mysticalPower==other.getPower());
}

void MysticalDocument::setPower(int addPower) {
    m_mysticalPower+=addPower;

}

int MysticalDocument::getPower() const {
    return m_mysticalPower;
}

MysticalDocument::MysticalDocument(const MysticalDocument &other) {
    this->m_mysticalPower=other.m_mysticalPower;
    this->m_content=other.m_content;
    this->m_number0fPages=other.m_number0fPages;
    this->m_summary=other.m_summary;
    this->m_documentName=other.m_documentName;
}

string MysticalDocument::getNumPages() const {
    return m_number0fPages;
}

string MysticalDocument::getSummary() const {
    return m_summary;
}

string MysticalDocument::getContent() const {
    return m_content;
}

void Scroll::makeSpell(const MysticalDocument &other) {
    if(dynamic_cast<const Scroll*>(&other)){
        this->setPower(other.getPower());
    }
}


void Tome::makeSpell(const MysticalDocument &other) {
    if(dynamic_cast<const Tome*>(&other)){
        this->setPower(other.getPower());
    }
}