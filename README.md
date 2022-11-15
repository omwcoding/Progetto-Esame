# Progetto-Esame

Prova del 14/11/2022 Laboratorio di Informatica.ITPS.A
Usando la modularizzazione per tipo di dato astratto, scrivere un programma in C che fornisca, da
menù utente, le seguenti funzionalità di dominio per calcoli su matrici:
1. Acquisizione da due file precedentemente creati dallo studente, di due matrici
i. una riga del file contiene una riga di una matrice, ciascun elemento di una riga è
un numero intero ed è separato dagli altri dal simbolo '#', ad esempio
4#50#23#123
ii. la matrice deve essere quadrata e di dimensione non inferiore a 4
iii. il nome dei file deve essere fornito da tastiera dall’utente
iv. impiegare una struttura statica a vettore
2. Uguaglianza. Verifica se due variabili del tipo di dato astratto sono uguali.
i. due variabili sono uguali se vi sono gli stessi numeri interi su due righe (una per
ciascuna matrice) con medesimo indice specificato da tastiera dall’utente
ii. l'operazione deve restituire una nuova variabile di tipo di dato astratto contenente
la riga uguale in entrambe le matrice (mentre tutti gli altri elementi sono
avvalorati a 0) se le due matrici sono uguali. secondo quanto detto sopra.
Altrimenti una nuova variabile con tutti gli elementi avvalorati a 0.
iii. il risultato sarà visualizzato a console e memorizzato sul file Uguaglianza.txt
3. Trasposta. L'operazione esegue il calcolo della trasposta su una variabile di dato astratto,
secondo nozione di algebra lineare
i. la matrice (una delle due acquisite) su cui lavorare deve essere specificata da
tastiera dall’utente
ii. l'operazione deve restituire una nuova variabile di tipo di dato astratto cosi
avvalorata
iii. il risultato sarà visualizzato a console e memorizzato nel file Trasposta.txt


CONSEGNA:
• consegna su portale ADA https://elearning.di.uniba.it/ (modalità Consegna
compito) entro le 10:00 delle 48 ore successive (oltre le ore 10:00 il portale si
chiude automaticamente)
• tutti i membri sul proprio account ADA devono consegnare il progetto (la
documentazione Doxygen deve riportare identificazione di tutti i membri)
• consegnare progetto in Code::blocks, come file compresso (ad esempio, .zip)
includendo
• codice sorgente ed eseguibile
• file input/output
• documentazione Doxygen, che deve riportare anche il testing e/o gli
interventi di programmazione difensiva
