ZJP
===
Wszystkie czasy sprawdzane srednia czasow ze 10 uruchomien 
programu w danej konfiguracji. Podzial na 2  tury sprawdzen.

MonteCarlo (1 000 000 000 prob)
==
Seq
--
> * 51.013

MPI
--
> - np 2 48.201
  - np 4 47.973
  - np 8 54.169
  - np 16 131.992
  
MonteCarlo (100 000 000 prob)
==
Seq
--
> * 4.801s

MPI 
--
>- np 1 5.566s
>- np 2 4.907s
>- np 4 4.847s
>- np 8 5.366s
>- np 16 10.739s

10 000 000 prob
==
Seq
--
> *0,78sec

MPI
--
> - np 4 0.48sec
  - np 8 0.55sec
  - np 16 1.21sec
M*V
==
Seq
--
> * 0.225s

MPI
--
>- np 1 0.103s
- np 2 1.125s
- np 3 1.132s
- np 4 1.147s
- np 8 1.224s
- np 16 1.332s

Calka (od -2 do 2 n= 512)
==
Seq
--
> * 0.00011487s

MPI
--
>- np 1 0.000092s
- np 2 0.000081s
- np 3 0.000173s
- np 4 0.000128s
- np 8 0.003553s
- np 16 0.01873s
