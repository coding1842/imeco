#!/bin/bash

#income.sh

echo "연소득을 입력하시면 소득에 대한 세금을 알려드립니다."
read -p "연소득: " val

if  [[ $val =~ ^-[0-9]+$ || $val == 0 ]]; then
    echo "연소득이 없어 세금을 납부하지 않아도 됩니다."
elif ! [[ $val =~ ^[0-9]+$ ]]; then
        echo "숫자를 입력해주세요."
        exit 1
fi

if [ $val -ge 100000000 ]; then
        tax=$(echo "$val * 0.13" | bc)
        tax=${tax%.*}
        echo "연소득: $val 세금: $tax"
elif [ $val -lt 100000000 ] && [ $val -ge 60000000 ]; then
        tax=$(echo "$val * 0.09" | bc)
        tax=${tax%.*}
        echo "연소득: $val 세금: $tax"
elif [ $val -lt 60000000 ] && [ $val -ge 50000000 ]; then
        tax=$(echo "$val * 0.07" | bc)
        tax=${tax%.*}
        echo "연소득: $val 세금: $tax"
elif [ $val -lt 50000000 ] && [ $val -ge 30000000 ]; then
        tax=$(echo "$val * 0.03" | bc)
        tax=${tax%.*}
        echo "연소득: $val 세금: $tax"
elif [ $val -lt 30000000 ] && [ $val -ge 1000 ]; then
        tax=$(echo "$val * 0.01" | bc)
        tax=${tax%.*}
        echo "연소득: $val 세금: $tax"
elif [ $val -lt 1000 ] && [ $val -ge 100 ]; then
        tax=$(echo "scale=2; $val * 0.01" | bc)
        echo "연소득: $val 세금: $tax"
elif [ $val -lt 100 ] && [ $val -ge 1 ]; then
        tax=$(echo "scale=2; $val * 0.01" | bc)
        tax="0$tax"
        echo "연소득: $val 세금: $tax"
fi

