
#define LOGSINTABLEBIT 8
#define LOGSINTABLELEN (1<<LOGSINTABLEBIT)
// round(-256.0*log2((sin((2*i+1)*PI/1024.0))))
static const uint16_t logsintable[LOGSINTABLELEN] = {
  2137, 1731, 1543, 1419, 1326, 1252, 1190, 1137,
  1091, 1050, 1013,  979,  949,  920,  894,  869,
   846,  825,  804,  785,  767,  749,  732,  717,
   701,  687,  672,  659,  646,  633,  621,  609,
   598,  587,  576,  566,  556,  546,  536,  527,
   518,  509,  501,  492,  484,  476,  468,  461,
   453,  446,  439,  432,  425,  418,  411,  405,
   399,  392,  386,  380,  375,  369,  363,  358,
   352,  347,  341,  336,  331,  326,  321,  316,
   311,  307,  302,  297,  293,  289,  284,  280,
   276,  271,  267,  263,  259,  255,  251,  248,
   244,  240,  236,  233,  229,  226,  222,  219,
   215,  212,  209,  205,  202,  199,  196,  193,
   190,  187,  184,  181,  178,  175,  172,  169,
   167,  164,  161,  159,  156,  153,  151,  148,
   146,  143,  141,  138,  136,  134,  131,  129,
   127,  125,  122,  120,  118,  116,  114,  112,
   110,  108,  106,  104,  102,  100,   98,   96,
    94,   92,   91,   89,   87,   85,   83,   82,
    80,   78,   77,   75,   74,   72,   70,   69,
    67,   66,   64,   63,   62,   60,   59,   57,
    56,   55,   53,   52,   51,   49,   48,   47,
    46,   45,   43,   42,   41,   40,   39,   38,
    37,   36,   35,   34,   33,   32,   31,   30,
    29,   28,   27,   26,   25,   24,   23,   23,
    22,   21,   20,   20,   19,   18,   17,   17,
    16,   15,   15,   14,   13,   13,   12,   12,
    11,   10,   10,    9,    9,    8,    8,    7,
     7,    7,    6,    6,    5,    5,    5,    4,
     4,    4,    3,    3,    3,    2,    2,    2,
     2,    1,    1,    1,    1,    1,    1,    1,
     0,    0,    0,    0,    0,    0,    0,    0,
};
#define LOGSINTABLEHIRESBIT 10
#define LOGSINTABLEHIRESLEN (1<<LOGSINTABLEHIRESBIT)
static const uint16_t logsintable_hires[LOGSINTABLEHIRESLEN] = {
  2649, 2243, 2055, 1931, 1838, 1764, 1702, 1649,
  1603, 1562, 1525, 1491, 1460, 1432, 1406, 1381,
  1358, 1336, 1316, 1296, 1278, 1260, 1243, 1227,
  1212, 1197, 1183, 1169, 1156, 1143, 1131, 1119,
  1108, 1096, 1086, 1075, 1065, 1055, 1045, 1036,
  1026, 1017, 1009, 1000,  992,  984,  976,  968,
   960,  952,  945,  938,  931,  924,  917,  910,
   904,  897,  891,  885,  879,  872,  867,  861,
   855,  849,  844,  838,  833,  827,  822,  817,
   812,  807,  802,  797,  792,  787,  783,  778,
   773,  769,  764,  760,  756,  751,  747,  743,
   739,  735,  730,  726,  722,  718,  715,  711,
   707,  703,  699,  696,  692,  688,  685,  681,
   678,  674,  671,  667,  664,  661,  657,  654,
   651,  647,  644,  641,  638,  635,  632,  629,
   626,  623,  620,  617,  614,  611,  608,  605,
   602,  599,  597,  594,  591,  588,  586,  583,
   580,  578,  575,  572,  570,  567,  565,  562,
   559,  557,  554,  552,  550,  547,  545,  542,
   540,  538,  535,  533,  531,  528,  526,  524,
   521,  519,  517,  515,  512,  510,  508,  506,
   504,  502,  500,  497,  495,  493,  491,  489,
   487,  485,  483,  481,  479,  477,  475,  473,
   471,  469,  467,  465,  463,  462,  460,  458,
   456,  454,  452,  450,  449,  447,  445,  443,
   441,  440,  438,  436,  434,  433,  431,  429,
   427,  426,  424,  422,  421,  419,  417,  416,
   414,  412,  411,  409,  407,  406,  404,  403,
   401,  399,  398,  396,  395,  393,  392,  390,
   389,  387,  386,  384,  383,  381,  380,  378,
   377,  375,  374,  372,  371,  369,  368,  367,
   365,  364,  362,  361,  360,  358,  357,  355,
   354,  353,  351,  350,  349,  347,  346,  345,
   343,  342,  341,  339,  338,  337,  336,  334,
   333,  332,  330,  329,  328,  327,  325,  324,
   323,  322,  320,  319,  318,  317,  316,  314,
   313,  312,  311,  310,  308,  307,  306,  305,
   304,  303,  301,  300,  299,  298,  297,  296,
   295,  294,  292,  291,  290,  289,  288,  287,
   286,  285,  284,  283,  281,  280,  279,  278,
   277,  276,  275,  274,  273,  272,  271,  270,
   269,  268,  267,  266,  265,  264,  263,  262,
   261,  260,  259,  258,  257,  256,  255,  254,
   253,  252,  251,  250,  249,  248,  247,  246,
   245,  244,  243,  242,  242,  241,  240,  239,
   238,  237,  236,  235,  234,  233,  232,  231,
   231,  230,  229,  228,  227,  226,  225,  224,
   224,  223,  222,  221,  220,  219,  218,  218,
   217,  216,  215,  214,  213,  212,  212,  211,
   210,  209,  208,  208,  207,  206,  205,  204,
   203,  203,  202,  201,  200,  199,  199,  198,
   197,  196,  196,  195,  194,  193,  192,  192,
   191,  190,  189,  189,  188,  187,  186,  186,
   185,  184,  183,  183,  182,  181,  180,  180,
   179,  178,  178,  177,  176,  175,  175,  174,
   173,  173,  172,  171,  171,  170,  169,  168,
   168,  167,  166,  166,  165,  164,  164,  163,
   162,  162,  161,  160,  160,  159,  158,  158,
   157,  156,  156,  155,  154,  154,  153,  152,
   152,  151,  151,  150,  149,  149,  148,  147,
   147,  146,  145,  145,  144,  144,  143,  142,
   142,  141,  141,  140,  139,  139,  138,  138,
   137,  136,  136,  135,  135,  134,  133,  133,
   132,  132,  131,  131,  130,  129,  129,  128,
   128,  127,  127,  126,  125,  125,  124,  124,
   123,  123,  122,  122,  121,  121,  120,  119,
   119,  118,  118,  117,  117,  116,  116,  115,
   115,  114,  114,  113,  113,  112,  112,  111,
   110,  110,  109,  109,  108,  108,  107,  107,
   106,  106,  105,  105,  104,  104,  103,  103,
   102,  102,  101,  101,  101,  100,  100,   99,
    99,   98,   98,   97,   97,   96,   96,   95,
    95,   94,   94,   93,   93,   93,   92,   92,
    91,   91,   90,   90,   89,   89,   88,   88,
    88,   87,   87,   86,   86,   85,   85,   85,
    84,   84,   83,   83,   82,   82,   82,   81,
    81,   80,   80,   79,   79,   79,   78,   78,
    77,   77,   77,   76,   76,   75,   75,   75,
    74,   74,   73,   73,   73,   72,   72,   71,
    71,   71,   70,   70,   69,   69,   69,   68,
    68,   68,   67,   67,   66,   66,   66,   65,
    65,   65,   64,   64,   64,   63,   63,   62,
    62,   62,   61,   61,   61,   60,   60,   60,
    59,   59,   59,   58,   58,   58,   57,   57,
    57,   56,   56,   55,   55,   55,   54,   54,
    54,   54,   53,   53,   53,   52,   52,   52,
    51,   51,   51,   50,   50,   50,   49,   49,
    49,   48,   48,   48,   47,   47,   47,   47,
    46,   46,   46,   45,   45,   45,   44,   44,
    44,   44,   43,   43,   43,   42,   42,   42,
    42,   41,   41,   41,   40,   40,   40,   40,
    39,   39,   39,   38,   38,   38,   38,   37,
    37,   37,   37,   36,   36,   36,   36,   35,
    35,   35,   35,   34,   34,   34,   34,   33,
    33,   33,   33,   32,   32,   32,   32,   31,
    31,   31,   31,   30,   30,   30,   30,   29,
    29,   29,   29,   28,   28,   28,   28,   28,
    27,   27,   27,   27,   26,   26,   26,   26,
    26,   25,   25,   25,   25,   24,   24,   24,
    24,   24,   23,   23,   23,   23,   23,   22,
    22,   22,   22,   22,   21,   21,   21,   21,
    21,   20,   20,   20,   20,   20,   19,   19,
    19,   19,   19,   18,   18,   18,   18,   18,
    18,   17,   17,   17,   17,   17,   17,   16,
    16,   16,   16,   16,   15,   15,   15,   15,
    15,   15,   15,   14,   14,   14,   14,   14,
    14,   13,   13,   13,   13,   13,   13,   12,
    12,   12,   12,   12,   12,   12,   11,   11,
    11,   11,   11,   11,   11,   10,   10,   10,
    10,   10,   10,   10,   10,    9,    9,    9,
     9,    9,    9,    9,    9,    8,    8,    8,
     8,    8,    8,    8,    8,    7,    7,    7,
     7,    7,    7,    7,    7,    7,    6,    6,
     6,    6,    6,    6,    6,    6,    6,    6,
     5,    5,    5,    5,    5,    5,    5,    5,
     5,    5,    4,    4,    4,    4,    4,    4,
     4,    4,    4,    4,    4,    4,    3,    3,
     3,    3,    3,    3,    3,    3,    3,    3,
     3,    3,    3,    3,    2,    2,    2,    2,
     2,    2,    2,    2,    2,    2,    2,    2,
     2,    2,    2,    2,    2,    1,    1,    1,
     1,    1,    1,    1,    1,    1,    1,    1,
     1,    1,    1,    1,    1,    1,    1,    1,
     1,    1,    1,    1,    1,    1,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,
     0,    0,    0,    0,    0,    0,    0,    0,
};

#define EXPTABLEBIT 8
#define EXPTABLELEN (1<<EXPTABLEBIT)
// round((1<<11) / pow(2.0, (i+1.0)/256.0))
static const uint16_t exptable[EXPTABLELEN] = {
  2042, 2037, 2031, 2026, 2020, 2015, 2010, 2004,
  1999, 1993, 1988, 1983, 1977, 1972, 1966, 1961,
  1956, 1951, 1945, 1940, 1935, 1930, 1924, 1919,
  1914, 1909, 1904, 1898, 1893, 1888, 1883, 1878,
  1873, 1868, 1863, 1858, 1853, 1848, 1843, 1838,
  1833, 1828, 1823, 1818, 1813, 1808, 1803, 1798,
  1794, 1789, 1784, 1779, 1774, 1769, 1765, 1760,
  1755, 1750, 1746, 1741, 1736, 1732, 1727, 1722,
  1717, 1713, 1708, 1704, 1699, 1694, 1690, 1685,
  1681, 1676, 1672, 1667, 1663, 1658, 1654, 1649,
  1645, 1640, 1636, 1631, 1627, 1623, 1618, 1614,
  1609, 1605, 1601, 1596, 1592, 1588, 1584, 1579,
  1575, 1571, 1566, 1562, 1558, 1554, 1550, 1545,
  1541, 1537, 1533, 1529, 1525, 1520, 1516, 1512,
  1508, 1504, 1500, 1496, 1492, 1488, 1484, 1480,
  1476, 1472, 1468, 1464, 1460, 1456, 1452, 1448,
  1444, 1440, 1436, 1433, 1429, 1425, 1421, 1417,
  1413, 1409, 1406, 1402, 1398, 1394, 1391, 1387,
  1383, 1379, 1376, 1372, 1368, 1364, 1361, 1357,
  1353, 1350, 1346, 1342, 1339, 1335, 1332, 1328,
  1324, 1321, 1317, 1314, 1310, 1307, 1303, 1300,
  1296, 1292, 1289, 1286, 1282, 1279, 1275, 1272,
  1268, 1265, 1261, 1258, 1255, 1251, 1248, 1244,
  1241, 1238, 1234, 1231, 1228, 1224, 1221, 1218,
  1214, 1211, 1208, 1205, 1201, 1198, 1195, 1192,
  1188, 1185, 1182, 1179, 1176, 1172, 1169, 1166,
  1163, 1160, 1157, 1154, 1150, 1147, 1144, 1141,
  1138, 1135, 1132, 1129, 1126, 1123, 1120, 1117,
  1114, 1111, 1108, 1105, 1102, 1099, 1096, 1093,
  1090, 1087, 1084, 1081, 1078, 1075, 1072, 1069,
  1066, 1064, 1061, 1058, 1055, 1052, 1049, 1046,
  1044, 1041, 1038, 1035, 1032, 1030, 1027, 1024,
};

static const uint8_t rateinctable[4*2][8] = {
// rates 0 - 47
  {0, 1, 0, 1, 0, 1, 0, 1},
  {0, 1, 0, 1, 1, 1, 0, 1},
  {0, 1, 1, 1, 0, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 1},

// rates 48 - 
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 2, 1, 1, 1, 2},
  {1, 2, 1, 2, 1, 2, 1, 2},
  {1, 2, 2, 2, 1, 2, 2, 2},
};

// datasheet 0.053Hz = 1
// [FD][keycode]
static const uint8_t dettable[4][32]={
  {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  },
  {
    0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
    2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7, 8, 8, 8, 8,
  },
  {
    1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5,
    5, 6, 6, 7, 8, 8, 9,10,11,12,13,14,16,16,16,16,
  },
  {
    2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 7,
    8, 8, 9,10,11,12,13,14,16,17,19,20,22,22,22,22,
  },
};