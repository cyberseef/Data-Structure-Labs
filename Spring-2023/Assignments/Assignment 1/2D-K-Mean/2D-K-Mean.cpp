#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include <sstream>   // for file-reading
#include <cmath>
#include <iomanip>
using namespace std;


class Point
{

public:
    double x, y;     // coordinates
    int cluster;     // no default cluster
    double minDist;  // default infinite dist to nearest cluster

    Point() {//constructor
        x = 0, y = 0;
        cluster = -1;
        minDist = 5000;

    }

    Point(double x1, double y1) {//loaded constructor
        x = x1, y = y1;
        cluster = -1;
        minDist =5000;

    }



    double distance(Point p) {

        double x1 = p.x - x; //calculating number to square in next step
        double y1 = p.y - y;
        double dist;

        dist = pow(x1, 2) + pow(y1, 2);       //calculating Euclidean distance
        dist = sqrt(dist);

        return dist;

    }
};


void initialcluster(Point* cluster, Point* data)
{
    srand(time(0));
    int n = 25;
    int index;
    for (int i = 0; i < 3; i++)
    {


        index = rand() / 30;

        
       
       
        cluster[i].x = data[index].x;
        cluster[i].y = data[index].y;
        n = n + 5;
    }

    cout << "cluster 1 : " << cluster[0].x << "   " << cluster[0].y<<"   \n";
    cout << "cluster 2 : " << cluster[1].x << "   " << cluster[1].y<<"\n";
    cout << "cluster 3 : " << cluster[2].x << "   " << cluster[2].y<<"\n";
}

Point* read_csv(Point* data)
{
    string line;
    int i = 0;
    ifstream file("C:\\Users\\%USERNAME%\\Desktop\\Assignment 1\\Resources\\driver-data.csv");
    getline(file, line);
    while (getline(file, line)) {
        stringstream lineStream(line);
        string bit;
        double x, y;
        getline(lineStream, bit, ',');

        getline(lineStream, bit, ',');
        x = stof(bit);
        getline(lineStream, bit, '\n');
        y = stof(bit);

        data[i].x = x;
        data[i].y = y;
        i++;



    }
    return data;


}


int main()
{

    Point* data = new Point[4000];
    Point* cluster = new Point[3];
    data=read_csv(data);
    cluster[0].x = 55.64;
    cluster[0].y = 6;

    cluster[1].x = 74.12;
    cluster[1].y = 9;

    cluster[2].x = 38.87;
    cluster[2].y = 15;

    double oldclu1x = cluster[0].x;
    double oldclu1y = cluster[0].y;
    double oldclu2x = cluster[1].x;
    double oldclu2y = cluster[1].y;
    double oldclu3x = cluster[2].x;
    double oldclu3y = cluster[2].y;

    initialcluster(cluster, data);
   
    do {


        //int f = 3;
        for (int k = 0; k < 3; k++)
        {
            for (int f = 0; f < 4000; f++)
            {
                double dist = cluster[k].distance(data[f]);


                if (dist < data[f].minDist)
                {
                    data[f].minDist = dist;
                    data[f].cluster = k + 1;
                }
            }

        }

        double total_x1 = 0;
        double total_y1 = 0;

        double total_x2 = 0;
        double total_y2 = 0;

        double total_x3 = 0;
        double total_y3 = 0;

        double total1 = 0;
        double total2 = 0;
        double total3 = 0;

        oldclu1x = cluster[0].x;
        oldclu1y = cluster[0].y;
        oldclu2x = cluster[1].x;
        oldclu2y = cluster[1].y;
        oldclu3x = cluster[2].x;
        oldclu3y = cluster[2].y;

        for (int i = 0; i < 4000; i++)
        {

            if (data[i].cluster == 1)
            {
                total_x1 = total_x1 + data[i].x;
                total_y1 = total_y1 + data[i].y;
                total1++;
            }
            else if (data[i].cluster == 2)
            {
                total_x2 = total_x2 + data[i].x;
                total_y2 = total_y2 + data[i].y;
                total2++;
            }
            else if (data[i].cluster == 3)
            {
                total_x3 = total_x3 + data[i].x;
                total_y3 = total_y3 + data[i].y;
                total3++;
            }

        }

        cluster[0].x = total_x1 / total1;
        cluster[0].y = total_y1 / total1;
        cluster[1].x = total_x2 / total2;
        cluster[1].y = total_y2 / total2;
        cluster[2].x = total_x3 / total3;
        cluster[2].y = total_y3 / total3;




        cout << "\ncluster 1 : " << cluster[0].x << "   " << cluster[0].y << "   \n";
        cout << "cluster 2 : " << cluster[1].x << "   " << cluster[1].y << "\n";
        cout << "cluster 3 : " << cluster[2].x << "   " << cluster[2].y << "\n\n";
        for (int i = 0; i < 1000; i++)
        {
            data[i].minDist = 50000;
            cout << data[i].x << "               " << data[i].y << "                  " << data[i].cluster << "\n";
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------------\n";




    } while (cluster[0].x != oldclu1x || cluster[0].y != oldclu1y || cluster[1].x != oldclu2x || cluster[1].y != oldclu2y || cluster[2].x != oldclu3x || cluster[2].y != oldclu3y);




    ofstream myfile;
    myfile.open("C:\\Users\\%USERNAME%\\Desktop\\Assignment 1\\Output\\output2d.csv");
    myfile << "x,y,c" << endl;

    for (int i = 0; i < 4000;i++) {
        myfile << data[i].x << "," << data[i].y << "," << data[i].cluster << endl;
    }
    myfile.close();

    


}