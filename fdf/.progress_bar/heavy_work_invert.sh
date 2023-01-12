#!/bin/bash

source progress_bar_invert.sh

tasks_in_total=37
for current_task in $(seq $tasks_in_total)
    do
    sleep 0.005 #simulate the task running
    show_progress $current_task $tasks_in_total
done
