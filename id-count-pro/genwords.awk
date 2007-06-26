BEGIN {
    comma = 0
}

{
    if (comma == 1) print ",";
    print "\""$1"\"";
    comma = 1;
}


END {
}
