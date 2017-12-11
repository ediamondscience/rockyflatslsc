#!/bin/bash
samplecalruns=(464 465 466 469 470 471)
samplebgruns=(467 472)
controlcalruns=(481 482 483 486 487 488)
controlbgruns=(484 489)
samplecalrunlen=(299 335 300 306 302 304)
samplebgrunlen=(300, 301)
controlcalrunlen=(306 301 300 300 301 312)
controlbgrunlen=(301 301)
selectbg=0



for i in 0 1 2; do root -l "edbsmac.c(${controlbgruns[selectbg]},${controlcalruns[i]},${controlbgrunlen[selectbg]},${controlcalrunlen[i]})";done 
