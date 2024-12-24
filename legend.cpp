#include<TH1F.h>
#include<iostream>
#include<fstream>
#include<TRandom2.h>
#include<TCanvas.h>
#include<TF1.h>
#include<TLegend.h>
using namespace std;

int legend(){
    TH1F * hist = new TH1F("hist", "histogram", 100, 0, 100);
    fstream file;
    file.open("data.txt", ios :: out);
    TRandom2 *rand = new TRandom2(0);

    for (int i =0 ; i<1000; i++){
        double r = rand -> Gaus(5,1)*10;
        file << r << endl;
    }
    file.close();

    file.open("data.txt", ios :: in);
    double value;

    while(1){
        file >> value;
        hist -> Fill (value);
        if (file.eof()) break;
    }
    TCanvas *c1 = new TCanvas();
    hist->SetStats(0);
    hist -> Draw();
    TF1 *fit = new TF1("fit", "gaus", 0, 100);
    fit -> SetParameters(50,50,10);
    hist -> Fit(fit, "R");

    TLegend * leg = new TLegend(.7,.7,.9,.9);
    leg -> AddEntry(fit, "fit", "l");
    leg -> AddEntry(hist, "data", "l");
    leg -> Draw();

    c1->SaveAs("legend.png");

    return 0;
}