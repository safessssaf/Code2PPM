#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

int screen_width = 500;
int screen_hight = 500;

std::string npp_rendering();

int main(int, char**)
{   
    std::fstream file;
    file.open("mbabe.ppm", std::ios::out);

    if(file.is_open())
    {
       file << "P3\n" << screen_width << ' ' << screen_hight << "\n255\n";
       file << npp_rendering();
    }
}
std::string npp_rendering()
{
    std::string readings;
    auto r = 0.0; 
    auto g = 0.0;
    auto b = 0.0;
    double radius = 0.0;
    int angle = 0;
    
    for(int h = 0 ; h < screen_hight; h++)
    {
        for(int w = 0 ; w < screen_width; w++)
        {
            radius = double(sqrt(powf(w - 260 ,2) + powf(h - 300,2)));

            radius = radius * sin(angle);
            
           // radius = abs(radius);
            if (radius < 50)
            {
                r = radius * 40;
                /*
                b = radius * 30;
                g = radius * 60;*/
            }
            else
            {
                r = 0.0;
                b = 0.0;
            }


            int r255 = int(r * 1);
            int g255 = int(g * 1);
            int b255 = int(b * 1);

            readings += std::to_string(r255) + ' ' + std::to_string(g255) + ' ' + std::to_string(b255) + "\n";

            if (angle > 360)
            {
                angle = 0;
            }
            angle ++;

            
        } 
    }
    return readings;
}

