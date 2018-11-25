#!/usr/bin/env python3
#!coding: utf-8

"""
This scripts will do an histogram view of a dataset given in argv
"""

import pandas as pds
import matplotlib.pyplot as plt

import sys as sys


def main(filename='./default.csv'):

    if len(sys.argv) == 2:
        filename = sys.argv[1]

    data = pds.read_table(filename, header=None, sep=' ', names=['valence'])

    plt.hist(data['valence'].dropna(), histtype='bar')
    plt.xlabel('Valence value')
    plt.ylabel('Number of occurences')
    plt.title('Histogram of valence value and the occurences of each')
    plt.show()


if __name__ == '__main__':
    main()
