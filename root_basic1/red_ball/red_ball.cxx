void red_ball()
{
    ifstream in;
    in.open("500red_ball.dat");
    Float_t x,y,z,q,p,r,sum500;
    Int_t nl=0;
    TFile *f=new TFile("sum_of_500red_ball.root","create");
    TH1F *h1=new TH1F("h1","sum of 500 red ball",20,1,200);
    while(1)
    {
        in>>x>>y>>z>>q>>p>>r;
        if(!in.good()) break;
        if(nl<600) 
            sum500=x+y+z+q+p+r;
            h1->Fill(sum500);
            nl++;
    }
    in.close();
    f->Write(); 
    
    ifstream in;
    in.open("1000red_ball.dat");
    Float_t i,j,k,m,n,b,sum1000;
    Int_t nline=0;
    TFile *f1=new TFile("sum_of_1000red_ball.root","create");
    TH1F *h2=new TH1F("h2","sum of 1000 red ball",20,1,200);
    while(1)
    {
        in>>i>>j>>k>>m>>n>>b;
        if(!in.good()) break;
        if(nline<1100) 
            sum1000=i+j+k+m+n+b;
            h2->Fill(sum1000);
            nline++;
    }     
    TCanvas *c1=new TCanvas("c1","a canvas",10,10,800,800);
    c1->Divide(2,1);
    c1->cd(1);
    h1->Fit("gaus"); 
    h1->Draw();
    c1->cd(2);
    h2->Fit("gaus");
    h2->Draw();
    gStyle->SetOptFit();
    in.close();
    f1->Write();    
    
}
