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
    double x, y,z;     // coordinates
    int cluster;     // no default cluster
    double minDist;  // default infinite dist to nearest cluster

    Point() {//constructor
        x = 0, y = 0, z=0;
        cluster = -1;
        minDist = 5000;

    }

    Point(double x1, double y1,double z1) {//loaded constructor
        x = x1, y = y1, z=z1;
        cluster = -1;
        minDist = 5000;

    }



    double distance(Point p) {

        double x1 = p.x - x; //calculating number to square in next step
        double y1 = p.y - y;
        double z1 = p.z - z;
        double dist;

        dist = pow(x1, 2) + pow(y1, 2)+pow(z1,2);       //calculating Euclidean distance
        dist = sqrt(dist);

        return dist;

    }
};


void initialcluster(Point* cluster, Point* data) //initial cluster
{
    srand(time(0));     //random seed
    int n = 25;
    int index;
    for (int i = 0; i < 3; i++)     //3 clusters
    {
        index = rand() / 200;       //random index

        cluster[i].x = data[index].x;   //assigning random data points to cluster
        cluster[i].y = data[index].y;   //assigning random data points to cluster
        cluster[i].z = data[index].z;   //assigning random data points to cluster
        n = n + 5;
    }

    cout << "cluster 1 : " << cluster[0].x << "   " << cluster[0].y << "   \n";     //printing initial cluster
    cout << "cluster 2 : " << cluster[1].x << "   " << cluster[1].y << "\n";
    cout << "cluster 3 : " << cluster[2].x << "   " << cluster[2].y << "\n";
}

Point* read_csv(Point* data)            //reading csv file
{
    string line;
    int i = 0;
    ifstream file("C:\\Users\\Cyberseef\\Desktop\\Assignment1\\segmented_customers-1.csv");     //file path
    getline(file, line);
    while (getline(file, line)) {       //reading line by line
        stringstream lineStream(line);
        string bit;
        double x, y,z;
        getline(lineStream, bit, ',');

        getline(lineStream, bit, ',');      //reading next value

        getline(lineStream, bit, ',');
        x = stof(bit);      //converting string to float
        getline(lineStream, bit, ',');      //reading next value
        y = stof(bit);

        getline(lineStream, bit, '\n');
        z = stof(bit);

        data[i].x = x;      //assigning values to data
        data[i].y = y;
        data[i].z = z;
        i++;



    }
    return data;


}


int main()
{

    Point* data = new Point[200];       //creating array of 200 points
    Point* cluster = new Point[3];      //creating array of 3 clusters
    data = read_csv(data);              //reading csv file
    cluster[0].x = 55.64;               //initial cluster
    cluster[0].y = 6;

    cluster[1].x = 74.12;
    cluster[1].y = 9;

    cluster[2].x = 38.87;
    cluster[2].y = 15;

    double oldclu1x = cluster[0].x;     //old cluster
    double oldclu1y = cluster[0].y;
    double oldclu1z = cluster[0].z;
    double oldclu2x = cluster[1].x;
    double oldclu2y = cluster[1].y;
    double oldclu2z = cluster[1].z;
    double oldclu3x = cluster[2].x;
    double oldclu3y = cluster[2].y;
    double oldclu3z = cluster[2].z;

    initialcluster(cluster, data);      //initial cluster

    do {


        //int f = 3;
        for (int k = 0; k < 3; k++)
        {
            for (int f = 0; f < 200; f++)
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
        double total_z1 = 0;

        double total_x2 = 0;
        double total_y2 = 0;
        double total_z2 = 0;

        double total_x3 = 0;
        double total_y3 = 0;
        double total_z3 = 0;

        double total1 = 0;
        double total2 = 0;
        double total3 = 0;

        oldclu1x = cluster[0].x;
        oldclu1y = cluster[0].y;
        oldclu1z = cluster[0].z;
        oldclu2x = cluster[1].x;
        oldclu2y = cluster[1].y;
        oldclu2z = cluster[1].z;
        oldclu3x = cluster[2].x;
        oldclu3y = cluster[2].y;
        oldclu3z = cluster[2].z;

        for (int i = 0; i < 200; i++)
        {

            if (data[i].cluster == 1)
            {
                total_x1 = total_x1 + data[i].x;
                total_y1 = total_y1 + data[i].y;
                total_z1 = total_z1 + data[i].z;
                total1++;
            }
            else if (data[i].cluster == 2)
            {
                total_x2 = total_x2 + data[i].x;
                total_y2 = total_y2 + data[i].y;
                total_z2 = total_z2 + data[i].z;
                total2++;
            }
            else if (data[i].cluster == 3)
            {
                total_x3 = total_x3 + data[i].x;
                total_y3 = total_y3 + data[i].y;
                total_z3 = total_z3 + data[i].z;
                total3++;
            }

        }

        cluster[0].x = total_x1 / total1;
        cluster[0].y = total_y1 / total1;
        cluster[0].z = total_z1 / total1;
        cluster[1].x = total_x2 / total2;
        cluster[1].y = total_y2 / total2;
        cluster[1].z = total_z2 / total2;
        cluster[2].x = total_x3 / total3;
        cluster[2].y = total_y3 / total3;
        cluster[2].z = total_z3 / total3;




        cout << "\ncluster 1 : " << cluster[0].x << "   " << cluster[0].y << "      "<<cluster[0].z<<"    \n";
        cout << "\ncluster 2 : " << cluster[1].x << "   " << cluster[1].y << "      " << cluster[1].z << "    \n";
        cout << "\ncluster 3 : " << cluster[2].x << "   " << cluster[2].y << "      " << cluster[2].z << "    \n\n";
        for (int i = 0; i < 200; i++)
        {
            data[i].minDist = 50000;
            cout << data[i].x << "               " << data[i].y << "                  "<<data[i].z<<"                       " << data[i].cluster << "\n";
        }
        cout << "\n------------------------------------------------------------------------------------------------------------------------\n";




    } while (cluster[0].x != oldclu1x || cluster[0].y != oldclu1y || cluster[0].z != oldclu1z || cluster[1].x != oldclu2x || cluster[1].y != oldclu2y || cluster[1].z != oldclu2z || cluster[2].x != oldclu3x || cluster[2].y != oldclu3y || cluster[2].z != oldclu3z); //checking if the cluster is same or not


    fstream fout;       //writing to csv file

    // opens an existing csv file or creates a new file.
    fout.open("C:\\Users\\Cyberseef\\Desktop\\Assignment1\\output.csv", ios::out | ios::app);

    ofstream myfile;
    myfile.open("C:\\Users\\Cyberseef\\Desktop\\Assignment1\\output.csv");
    myfile << "x,y,z,c" << endl;

    for (int i = 0; i < 200; i++) {     //writing to csv file
        myfile << data[i].x << "," << data[i].y << "," << data[i].z << "," << data[i].cluster << endl;
    }
    myfile.close();




}