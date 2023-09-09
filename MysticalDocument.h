#ifndef THE_MYSTICAL_LIBRARY_MANAGER_MYSTICALDOCUMENT_H
#define THE_MYSTICAL_LIBRARY_MANAGER_MYSTICALDOCUMENT_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class MysticalDocument {
public:
    MysticalDocument(const string& name,const string& summary, const string& content, string numPages,int power=0):
            m_documentName(name),m_summary(summary),m_content(content), m_number0fPages(numPages),m_mysticalPower(power){}
    virtual ~MysticalDocument()=default;
    MysticalDocument(const MysticalDocument& other);
    string getName() const;
    string getNumPages() const;
    int getPower() const;
    string getSummary() const;
    string getContent() const;

    void setPower(int addPower);
    friend ostream &operator<<(ostream& os, const MysticalDocument& m);
    bool operator<(const MysticalDocument& other) const;
    bool operator>(const MysticalDocument& other) const;
    bool operator==(const MysticalDocument& other) const;
    virtual void makeSpell(const MysticalDocument& other)=0;
protected:
    virtual void print(ostream& os) const{
        os<<"Mystical Document Info: "<<endl<<"Name: "<<m_documentName <<endl
       <<"             Number of pages: "<<m_number0fPages<<", Mystical power levels:"<<m_mysticalPower <<endl <<
       "Summary: " <<m_summary<<endl<<endl<<m_content;
    }
    string m_documentName;
    string m_summary;
    string m_content;
    string m_number0fPages;
    int m_mysticalPower;//0-1000
};
class Scroll:public MysticalDocument{
public:
    Scroll(const string& name,const string& summary, const string& content, string numPages, int power=0): MysticalDocument(name,summary,content,numPages,power){}
    explicit Scroll(const MysticalDocument& other) : MysticalDocument(other) {}
    void makeSpell(const MysticalDocument& other) override;

};
class Tome:public MysticalDocument{
public:
    Tome(const string& name,const string& summary, const string& content, string numPages,int power=0): MysticalDocument(name,summary,content,numPages,power){}
    explicit Tome(const MysticalDocument& other) : MysticalDocument(other) {}
    void makeSpell(const MysticalDocument& other) override;
};


#endif //THE_MYSTICAL_LIBRARY_MANAGER_MYSTICALDOCUMENT_H
