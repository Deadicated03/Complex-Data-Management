# Complex-Data-Management
This repository contains implementations for complex data management, spatial data indexing, and top-k query processing

-----------------------------------------------------------------------------------------------------------------------------------------------

📌 Description of qc.c (`composite query`)

This program processes two CSV files, `R.csv` and `S.csv`, to compute the sum of column E from S for all entries where R.A = S.A and R.C = 7. 
It efficiently scans both files and outputs the results into `O3.csv`. This implements the following SQL query:

SELECT S.A, SUM(S.E)  
FROM R, S  
WHERE R.A = S.A AND R.C = 7  
GROUP BY S.A;


1️⃣ Compile the program (if using GCC):
`gcc -o qc qc.c`

2️⃣ Run the program:
`./qc`

3️⃣ Ensure the input files exist in the same directory:
`R.csv → Contains table R(A, B, C)`
`S.csv → Contains table S(D, A, E)`

-----------------------------------------------------------------------------------------------------------------------------------------------

📌 Description of gwa.c (`group-by with aggregation`)

This program implements a group-by with aggregation operation using a modified merge sort algorithm. 
It processes a CSV file containing a table with three numeric columns and performs aggregation (SUM, MIN, or MAX) on a selected attribute while grouping by another attribute.

1️⃣ Compile the program (if using GCC):
`gcc -o gwa gwa.c`

2️⃣ Run the program:
`./gwa input.csv group_by_column aggregation_column aggregation_function`

Example:
`./gwa R.csv 1 2 max`

-----------------------------------------------------------------------------------------------------------------------------------------------

📌 Description of mj.c (`merge join`):

This program implements a merge-join algorithm to perform a natural join between two CSV files,
`R.csv` and `S.csv`, and outputs the result to a new file called `O2.csv`. It corresponds to the SQL query:

1️⃣ Compile the program (if using GCC):
`gcc -o merge_join merge_join.c`

2️⃣ Run the program:
`./merge_join`

3️⃣ Ensure the input files (R.csv and S.csv) are in the same directory.


more programs will be added soon












