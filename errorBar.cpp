#include<iostream>
#include<TGraph.h>
#include<TCanvas.h>
#include<TGraphErrors.h>
#include<fstream>
#include<TF1.h>
using namespace std;

int error(){
    TCanvas * canvas = new TCanvas();
    TGraphErrors *graph = new TGraphErrors();

    fstream file;

    file.open("data3.txt", ios::in);
    double x, y, ex, ey;
    int n = 0;

    while(1){
        file >> x >> y >> ex >> ey;

        n = graph -> GetN();
        graph -> SetPoint(n,x,y);
        graph -> SetPointError(n, ex,ey);

        if (file.eof()) break;

    }
    file.close();
    TF1 *fit = new TF1("fit", "pol1",0,5);
    graph -> Fit(fit);
    graph -> Draw("A*");
    
    canvas->SaveAs("errorbar.png");

    return 0;
}