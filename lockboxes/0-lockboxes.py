#!/usr/bin/python3
"""stop si tout ne peut pas etre ouvert"""


def canUnlockAll(boxes):
    """stop si tout ne peut pas etre ouvert"""
    ouvertes = set([0])
    listpeutouvrir = list(boxes[0])

    for key in listpeutouvrir:
        if key < len(boxes) and key not in ouvertes:
            ouvertes.add(key)
            listpeutouvrir.extend(boxes[key])

    return len(ouvertes) == len(boxes)
