void not_ordered()
{ 
    ifstream in;
    in.open("not_ordered.dat");
    Float_t x,y,z,q,p,r;
    Int_t nl=0;
    TFile *f=new TFile("not_ordered.root","create");
    TNtuple *ntuple=new TNtuple("ntuple","red_number(not_ordered)","x:y:z:q:p:r");
    while(1)
    {
        in>>x>>y>>z>>q>>p>>r;
        if(!in.good()) break;
        if(nl<1500)                    
            ntuple->Fill(x,y,z,q,p,r);
            nl++;
    }
    TCanvas *c1=new TCanvas("c1","a canvas",10,10,900,900);
    c1->Divide(2,1);
    c1->cd(1);
    ntuple->Draw("x:r");
    c1->cd(2);
    ntuple->Draw("x:x+y+z+q+p+r");
    in.close();
    f->Write();
}
