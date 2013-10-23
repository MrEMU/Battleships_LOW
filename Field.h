#ifndef FIELD_H
#define FIELD_H
#include <vector>


class Field
{
    public:
         Field();
         virtual ~Field();
         void show();
         bool setship(std::vector<int>, int);
         bool testhit(std::vector<int>);
         bool write_position(char,std::vector<int>);
         char Feld[10][10] = {{' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'},
                        {'1', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'2', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'3', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'4', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'5', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'6', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'7', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'8', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'9', '~', '~', '~', '~', '~', '~', '~', '~', '~'}};;
    protected:
    private:
};

#endif //FIELD_H
