# Complex-Data-Management
This repository contains implementations for complex data management, spatial data indexing, and top-k query processing


📌 Description of qc.c
This program processes two CSV files, R.csv and S.csv, to compute the sum of column E from S for all entries where R.A = S.A and R.C = 7. 
It efficiently scans both files and outputs the results into O3.csv. This implements the following SQL query:

SELECT S.A, SUM(S.E)
FROM R, S
WHERE R.A = S.A AND R.C = 7
GROUP BY S.A;

1️⃣ Compile the program (if using GCC):

gcc -o qc qc.c

2️⃣ Run the program:

./qc

3️⃣ Ensure the input files exist in the same directory:

R.csv → Contains table R(A, B, C)
S.csv → Contains table S(D, A, E)
