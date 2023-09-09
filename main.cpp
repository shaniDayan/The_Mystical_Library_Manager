#include <iostream>
#include "MysticalDocument.h"
#include "containerDoc.h"

int main() {
    const Scroll m("shani", "shani", "shani", "34", 10);
    const Tome a("Aya", "aya", "aya", "34", 350);

    containerDoc  he;
    he.addDocument(m);
    he.addDocument(a);
    he.sortByPower();
    he.saveToFile(R"(C:\Users\shani\CLionProjects\The_Mystical_Library_Manager\outfile.txt)");
    he.loadFromFile(R"(C:\Users\shani\CLionProjects\The_Mystical_Library_Manager\infile.txt)");
    he.printAll();
    return 0;
}

