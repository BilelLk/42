#!/bin/bash

red=$(tput setaf 9)
normal=$(tput sgr0)
green=$(tput setaf 2)

bar_size=100
bar_char_done="-"
bar_char_todo="█"
bar_percentage_scale=0

function show_progress {
    current="$1"
    total="$2"

    # calculate the progress in percentage
    percent=$(bc <<< "scale=$bar_percentage_scale; 100 - (100 * $current / $total)" )
    # The number of done and todo characters
    done=$(bc <<< "scale=0; $bar_size - ( $bar_size * $percent / 100 )" )
    todo=$(bc <<< "scale=0; $bar_size * $percent / 100" )

    # build the done and todo sub-bars
    done_sub_bar=$(printf "%${done}s" | tr " " "${bar_char_done}")
    todo_sub_bar=$(printf "%${todo}s" | tr " " "${bar_char_todo}")

    # output the bar
    echo -ne "${normal}\rProgress of Deletion: [${red}${done_sub_bar}${green}${todo_sub_bar}${normal}] ${percent}%"

    if [ $total -eq $current ]; then
        echo -e "${red}\nCleaning is done 🧹"
    fi
}
