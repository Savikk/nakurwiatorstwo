Labirynt użyty w pliku dane.txt (generator nie do końca gotowy)

1--2--3--4--5--6--7--8--9--10
|  |  |  |  |  |  |     |  |
11-12-13-14-15-16-17 # 19-20
|  |  |  |  |  |        |  |
21-22-23-24-25-26 # 28-29-30
|  |  |  |  |        |  |  |
31-32-33-34-35 # 37-38-39-40
|  |  |  |        |  |  |  |
41-42-43-44  # 46-47-48-49-50


S := empty sequence
u := target
  while previous[u] is defined:    
      insert u at the beginning of S 
      u := previous[u]               
  end while ;
  
