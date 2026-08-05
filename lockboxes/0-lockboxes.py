#!/usr/bin/env python3
"""Module that determines if all locked boxes can be opened."""


def canUnlockAll(boxes):
    """Return True if all boxes can be opened, else False."""
    ouvertes = set([0])
    listpeutouvrir = list(boxes[0])

    for key in listpeutouvrir:
        if key < len(boxes) and key not in ouvertes:
            ouvertes.add(key)
            listpeutouvrir.extend(boxes[key])

    return len(ouvertes) == len(boxes)
