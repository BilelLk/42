# #!/bin/bash

# red=$(tput setaf 9)
# normal=$(tput sgr0)
# green=$(tput setaf 2)

# bar_size=100
# bar_char_done="█"
# bar_char_todo="-"
# bar_percentage_scale=2

# function show_progress {
#     current="$2"
#     total="$1"
#     speed="$3" # speed parameter added

#     # calculate the progress in percentage
#     percent=$(bc <<< "scale=$bar_percentage_scale; 100 * $current / $total" )
#     # The number of done and todo characters
#     done=$(bc <<< "scale=0; $bar_size * $percent / 100" )
#     todo=$(bc <<< "scale=0; $bar_size - $done" )

#     # build the done and todo sub-bars
#     done_sub_bar=$(printf "%${done}s" | tr " " "${bar_char_done}")
#     todo_sub_bar=$(printf "%${todo}s" | tr " " "${bar_char_todo}")

#     # output the bar
#     echo -ne "${normal}\rProgress of Compilation: [${green}${done_sub_bar}${red}${todo_sub_bar}${normal}] ${percent}%"
#     if [ $percent -eq 50 ]; then
#          sleep $(bc <<< "scale=2; $speed*$current/$total")
#     fi
#     if [ $total -eq $current ]; then
#          echo -e "${green}\nCompiling DONE!💪"
#     fi
# }

# # Example usage
# total=100
# speed=1
# for ((i=1; i<=$total; i++))
# do
#     show_progress $total $i $speed
# done



#!/bin/bash

red=$(tput setaf 9)
normal=$(tput sgr0)
green=$(tput setaf 2)

bar_size=100
bar_char_done="█"
bar_char_todo="-"
bar_percentage_scale=2

function show_progress {
    current="$2"
    total="$1"

    # calculate the progress in percentage
    percent=$(bc <<< "scale=$bar_percentage_scale; 100 * $current / $total" )
    # The number of done and todo characters
    done=$(bc <<< "scale=0; $bar_size * $percent / 100" )
    todo=$(bc <<< "scale=0; $bar_size - $done" )

    # build the done and todo sub-bars
    done_sub_bar=$(printf "%${done}s" | tr " " "${bar_char_done}")
    todo_sub_bar=$(printf "%${todo}s" | tr " " "${bar_char_todo}")

    # output the bar
    echo -ne "${normal}\rProgress of Compilation: [${green}${done_sub_bar}${red}${todo_sub_bar}${normal}] ${percent}%"

    if [ $total -eq $current ]; then
         echo -e "${green}\nCompiling DONE!💪"
    fi
}
