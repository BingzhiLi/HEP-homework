void difference()
{ 
    ifstream in;
    in.open("500red_ball.dat");
    Float_t x,y,z,q,p,r,dif;
    Int_t nl=0;
    TFile *f=new TFile("difference.root","create");   
    TH1F *h1=new TH1F("h1","dif",20,1,32);
    TNtuple *ntuple=new TNtuple("ntuple","red_number","x:y:z:q:p:r");
    while(1)
    {
        in>>x>>y>>z>>q>>p>>r;
        if(!in.good()) break;
        if(nl<600)  
            dif=r-x;
            h1->Fill(dif);
            ntuple->Fill(x,y,z,q,p,r);
            nl++;
    } 
    TCanvas *c1=new TCanvas("c1","a canvas",10,10,900,900);
    c1->Divide(2,1);
    c1->cd(1);
    ntuple->Draw("r-x");
    c1->cd(2);
    h1->Draw();
    in.close();
    f->Write();
}
