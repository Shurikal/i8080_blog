# Test if module can be imported

import pytest
import _i8080

def test_docstring():
    assert _i8080.__doc__ == "This module is for emulating the Intel 8080 CPU."


def test_add():
    assert _i8080.add(1, 2) == 3
    assert _i8080.add(1,-10) == -9