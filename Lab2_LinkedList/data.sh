#!/bin/bash

# Use this script to scrape data from the web using the provided shell scripts provided.

wget -O - "https://api.blockchain.info/charts/market-price?format=csv" | head -n 30 | cut -d ',' -f 2 | cut -d '.' -f 1 > data.txt





