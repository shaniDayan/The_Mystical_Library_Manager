
#ifndef THE_MYSTICAL_LIBRARY_MANAGER_MYSTICALLIBRARYEXCEPTION_H
#define THE_MYSTICAL_LIBRARY_MANAGER_MYSTICALLIBRARYEXCEPTION_H

#include <iostream>
using namespace std;

class MysticalLibraryException: public exception{
public:
    const char* what() const noexcept  override{
        return "Invalid Input";
    }
};

#endif //THE_MYSTICAL_LIBRARY_MANAGER_MYSTICALLIBRARYEXCEPTION_H
