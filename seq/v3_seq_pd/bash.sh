#!/bin/sh
#SBATCH --job-name=serial_job_test    # Job name
#SBATCH --mail-type=ALL               # Mail events (NONE, BEGIN, END, FAIL, ALL)
#SBATCH --mail-user=<email_address>   # Where to send mail	
#SBATCH --ntasks=1                    # Run on a single CPU
#SBATCH --mem=600mb                   # Memory limit
#SBATCH --time=00:05:00               # Time limit hrs:min:sec
#SBATCH --output=serial_test_%j.out   # Standard output and error log
 
srun -n 16 ./ttt

