import csv
N=250000
k=['MIDNIGHT ARP','BROKEN KEYS','DARK BELL','LOW GUITAR','HAUNTED PLUCK','CLOUD PAD','NEON RHODES','FROZEN PIANO','EMPTY ROOM','NIGHT DRIVE']
m=['Obsidian','Afterglow','Nocturne','Wasted','Velvet','Static','Blue Hour','Ghost','Rainfall','Eclipse']
with open('preset_index.csv','w',newline='',encoding='utf-8') as f:
 w=csv.writer(f);w.writerow(['program','name','category'])
 for i in range(N):w.writerow([i+1,f'{k[i%10]} • {m[(i//10)%10]} • {i+1}',k[i%10]])
