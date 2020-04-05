#include "vip.h"


vip::vip(cliente cli, piscina pis, palestra pal): cliente (cli), piscina(pis), palestra(pal){}

vip::vip(char n, char c, unsigned int g, unsigned int m, unsigned int a,string cf, char lN, char r, char v, unsigned int num,string nt,string em,bool s,bool cn,string nipi,unsigned int sgpi,unsigned int smpi,unsigned int sapi, bool sc,string nipa,unsigned int sgpa,unsigned int smpa,unsigned int sapa):cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s), piscina(cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),cn,nipi,sgpi,smpi,sapi),palestra(cliente(n,c,g,m,a,cf,lN,r,v,num,nt,em,s),sc,nipa,sgpa,smpa,sapa){}
