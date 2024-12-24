#include <TCanvas.h>
#include <TH1F.h>
#include<TGraph.h>

int main(){
    double x[5] = {1,2,3,4,5};
    double y[5] = {1,4,9,16,25};

    TGraph * graph = new TGraph(5,x,y);

    TCanvas * canvas = new TCanvas("Canvas", "eg",800,800);

    graph -> Draw("A*");
    canvas->SaveAs("graph.png");
    
}