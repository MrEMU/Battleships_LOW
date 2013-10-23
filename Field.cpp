#include "Field.h"
#include <iostream>
#include <vector>


Field::Field()
{




}

Field::~Field()
{
    //dtor
}

void Field::show()
{
 for(int i=0;i<=9;i++)
 {
     std::cout << "\n\n";
     for(int j=0;j<=9;j++)
     {
         std::cout << (Feld[i][j]) << "  ";
     }
 }
}


bool Field::setship(std::vector<int> pcoords1, int lenght)
 {
     int exchange;

    if (pcoords1[0] == pcoords1[2])
    {
        if (pcoords1[1] > pcoords1[3])
            {
                exchange = pcoords1[1];
                pcoords1[1] = pcoords1[3];
                pcoords1[3] = exchange;
            }
        if  ((pcoords1[3] - pcoords1[1] + 1) != lenght)
        {
            return false;
        }
        for(int i=0;i<lenght;i++)
        {
            if (Feld[pcoords1[1]+i][pcoords1[0]] != '~')
            {
                return false;
            }
            else
            {
               Feld[pcoords1[1]+i][pcoords1[0]] = '#';
            }

        }
        return true;
    }

    else if (pcoords1[1] == pcoords1[3])
    {
        if (pcoords1[0] > pcoords1[2])
            {
                exchange = pcoords1[0];
                pcoords1[0] = pcoords1[2];
                pcoords1[0] = exchange;
            }
        if  ((pcoords1[2] - pcoords1[0]+1) != lenght)
        {
            return false;
        }
        for(int i=0;i<lenght;i++)
        {
            if (Feld[pcoords1[1]][pcoords1[0]+i] != '~')
            {
                return false;
            }
        }
        for(int i=0;i<lenght;i++)

        {
            Feld[pcoords1[1]][pcoords1[0]+i] = '#';
        }
        return true;
    }

    else
    {
        return false;
    }
 }

bool Field::testhit(std::vector<int> Coords)
{
    if (Feld[Coords[1]][Coords[0]] == '#')
    {
        return true;
    }
    else if (Feld[Coords[1]][Coords[0]] == '~')
    {
        return false;
    }
    else
    {
        std::cout << "You fired out of the battlegrounds";
        return false;
    }

}

bool Field::write_position(char towrite,std::vector<int> Coords)
{
    if (Coords[0] == 0 || Coords[1] == 0)
    {
        return false;
    }
    else
    {
        Feld[Coords[1]][Coords[0]] = towrite;
        return true;
    }

}
