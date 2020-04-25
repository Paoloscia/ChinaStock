#include "vip.h"


vip::vip(cliente cli, piscina pis, palestra pal): cliente (cli), piscina(pis), palestra(pal){}

vip *vip::clone() const
{
    return new vip(*this);
}

vip::vip(string n, string c, int g, int m, int a,string cf, string lN, string r, string v, unsigned int num,string nt,string em,bool s,bool cn,string nipi,int sgpi,int smpi,int sapi, bool sc,string nipa,int sgpa,int smpa,int sapa):cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s), piscina(cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),cn,nipi,sgpi,smpi,sapi),palestra(cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),sc,nipa,sgpa,smpa,sapa){}
