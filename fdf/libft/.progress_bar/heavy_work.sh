#!/bin/bash

source progress_bar.sh

tasks_in_total=37
for current_task in $(seq $tasks_in_total)
    do
    sleep 0.005 #simulate the task running
    show_progress $tasks_in_total $current_task
done
