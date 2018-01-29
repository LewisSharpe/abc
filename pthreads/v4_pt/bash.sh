#!/bin/bash
#SBATCH --job-name=my_job
#SBATCH --output=output.txt
#
#SBATCH --ntasks=32 
#SBATCH --time=5:00
#SBATCH --mem-per-cpu=6000

./ttt_pt

