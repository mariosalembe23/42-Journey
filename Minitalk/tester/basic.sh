#!/bin/zsh
# Colors
Black='\e[0;30m'
D_Gray='\e[1;30m'
Red='\e[0;31m'
L_Red='\e[1;31m'
Green='\e[0;32m'
L_Green='\e[1;32m'
Orange='\e[0;33m'
Yellow='\e[1;33m'
Blue='\e[0;34m'
L_Blue='\e[1;34m'
Purple='\e[0;35m'
L_Purple='\e[1;35m'
Cyan='\e[0;36m'
L_Cyan='\e[1;36m'
L_Gray='\e[0;37m'
White='\e[1;37m'
NC='\e[0m'

#--INITS--#
ONE="1s"
HALF="0.500s"
THIRD="0.333s"
PATH_TO_CLIENT="./client"

for init in t1 t2 t3 t4 t5 p_id
do
    export $init=0
done

speed_tester=$(cat <<EOF
.
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
...................................................................................................
EOF
)
tester1=$(cat <<EOF
.
Hello 42
EOF
)
tester2=$(cat <<EOF
.
!#$%&''()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_abcdefghijklmnopqrstuvwxyz{|}~
EOF
)
tester3=$(cat <<EOF
.
😎 Hello 42 Luanda 😎
EOF
)
tester4=$(cat <<EOF
.
😀 😃 😄 😁 😆 😅 😂 🤣 😊 😇
🙂 🙃 😉 😌 😍 🥰 😘 😗 😙 😚
😋 😛 😝 😜 🤪 🤨 🧐 🤓 😎 🥳
🤗 🤡 😏 😒 😞 😔 😟 😕 🙁 ☹️
😣 😖 😫 😩 🥺 😢 😭 😤 😠 😡
🤬 🤯 😳 🥵 🥶 😱 😨 😰 😥 😓
🤔 🤭 🤫 🤥 😶 😐 😑 😬 🙄 😯
😦 😧 😮 😲 🥱 😴 🤤 😪 😵 🤐
🥴 🤢 🤮 🤧 😷 🤒 🤕 🤑 🤠 😈
👿 👹 👺 🤡 💩 👻 💀 ☠️ 👽 👾
🤖 🎃 😺 😸 😹 😻 😼 😽 🙀 😿
😾 🐱 🐶 🐭 🐹 🐰 🦊 🦝 🐻 🐼
🐨 🐯 🦁 🐮 🐷 🐽 🐸 🐵 🐔 🐧
🐦 🐤 🐣 🐥 🦆 🦢 🦉 🦩 🦚 🦜
🦢 🦩 🦉 🦚 🦜 🦢 🦩 🦉 🦚 🦜
EOF
)
tester5=$(cat <<EOF
.
██╗  ██╗██████╗     ██╗     ██╗   ██╗ █████╗ ███╗   ██╗██████╗  █████╗ 
██║  ██║╚════██╗    ██║     ██║   ██║██╔══██╗████╗  ██║██╔══██╗██╔══██╗
███████║ █████╔╝    ██║     ██║   ██║███████║██╔██╗ ██║██║  ██║███████║
╚════██║██╔═══╝     ██║     ██║   ██║██╔══██║██║╚██╗██║██║  ██║██╔══██║
     ██║███████╗    ███████╗╚██████╔╝██║  ██║██║ ╚████║██████╔╝██║  ██║
     ╚═╝╚══════╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝ ╚═╝  ╚═╝
EOF
)
tester6=$(cat <<EOF
.
██╗   ██ ███████╗███████╗██████═╗ 
██║  ██╝ ██╔════╝██╔════╝██    ██╗
██████╝  ███████╗███████╗██████╔═╝
██╔══██╗ ██╔════╝██╔════╝██╔═══╝  
██║  ╚██╗███████╗███████╗██║      
╚═╝   ╚═╝╚══════╝╚══════╝╚═╝      
EOF
)
tester7=$(cat <<EOF
.
 ██████╗ █████╗ ██╗     ███╗   ███╗
██╔════╝██╔══██╗██║     ████╗ ████║
██║     ███████║██║     ██╔████╝██║
██║     ██╔══██║██║     ██║╚██╝ ██║
║██████╗██║  ██║███████╗██║ ╚╝  ██║
╚══════╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝
EOF
)

#--ERROR--#
display_error() {
  echo "[ERROR] Please enter correct arg when launching."
  exit 1
}

#--CODE--#
chmod +x "$PATH_TO_CLIENT"
echo "#-------------------------#"
echo "42 LUANDA MINITALK TESTER"
echo "#-------------------------#"
echo -n "Executing"
j=0
while [ $j -lt 3 ]
do
    echo -n "."
    sleep 1
    j=$((j + 1))
done
echo

for i in "$@"
do
    case $i in
        -m) t1=1 t2=1;;
        -b) t3=1 t4=1 t5=1;;
        *)
            if [[ "$p_id" = 0 ]]
            then
                p_id="$i"
            else
                display_error
            fi
            ;;
    esac
done

#--VERIF_PID--#
if ! [[ $p_id =~ [0-9]+ ]]
then 
    display_error
fi

#--SPEED--#
echo
echo "${L_Green} [Speed test]\tTime to print 1 000 char ${NC}"

timeout $ONE $PATH_TO_CLIENT $p_id "$speed_tester"

#--TESTS--#

if [[ $t1 == 1 ]]
then
clear
echo "Start Test Number: 01 ASCII"
printf '    '
timeout $THIRD $PATH_TO_CLIENT $p_id "$tester1"
echo
fi

if [[ $t2 == 1 ]]
then
clear
echo "Start Test Number: 02 ALL ASCII"
printf '    '
timeout $HALF $PATH_TO_CLIENT $p_id "$tester2"
echo
fi

if [[ $t3 == 1 ]]
then
clear
echo "Start Test Number: 03 UNICODE"
printf '    '
timeout $THIRD $PATH_TO_CLIENT $p_id "$tester3"
echo
fi

if [[ $t4 == 1 ]]
then
clear
echo "Start Test Number: 04 ALL UNICODE"
printf '    '
timeout $HALF $PATH_TO_CLIENT $p_id "$tester4"
echo
fi

if [[ $t5 == 1 ]]
then
clear
echo "Start Test Number: 05 GO CRAZY"
printf '    '
k=0
while [[ $k -lt 10 ]]
do
timeout $THIRD $PATH_TO_CLIENT $p_id "$tester5"
timeout $THIRD $PATH_TO_CLIENT $p_id "$tester6"
timeout $THIRD $PATH_TO_CLIENT $p_id "$tester7"
k=$((k + 1))
echo
done
fi

echo "p_id: $p_id, t1: $t1, t2: $t2, t3: $t3, t4: $t4, t5: $t5 tm: $tm"
