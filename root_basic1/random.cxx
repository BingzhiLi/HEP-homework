void random()
{    
    TH1F* h=new TH1F("h","random histogram",20,-1,1);
    for(int i=0;i<1000;i++)
    {
        h->Fill(gRandom->Uniform(-1,1));
    }
    h->Draw();
}
