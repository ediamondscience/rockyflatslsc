#!/bin/bash
samplecalruns=(531 532 533)
samplebgruns=(530)
controlcalruns=(535 536 537)
controlbgruns=(534)
samplecalrunlen=(308 451 301)
samplebgrunlen=(82444)
controlcalrunlen=(302 408 501)
controlbgrunlen=(83585)
selectbg=0



for i in 0 1 2; do root -l "edbsmac.c(${samplebgruns[selectbg]},${samplecalruns[i]},${samplebgrunlen[selectbg]},${samplecalrunlen[i]})";done 
