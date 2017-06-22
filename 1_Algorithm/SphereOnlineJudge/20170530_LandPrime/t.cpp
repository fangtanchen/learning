#include<stdio.h>
#include<queue>
#include<string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
using namespace std;
int pos[1005]= {-1,5133,9592,13848,17984,22044,25997,29977,33860,37706,41538,45322,49098,52831,56543,60238,63951,67617,71274,74907,78498,82134,85714,89302,92938,96469,100021,103544,107126,110630,114155,117663,121127,124634,128141,131608,135072,138542,142029,145502,148933,152382,155805,159250,162662,166081,169511,172873,176302,179684,183072,186462,189880,193256,196645,199993,203362,206789,210109,213453,216816,220136,223492,226835,230209,233577,236900,240230,243539,246909,250150,253412,256726,260064,263397,266717,269987,273322,276611,279921,283146,286490,289774,293010,296314,299583,302824,306084,309335,312666,315948,319164,322441,325706,328964,332219,335439,338694,341992,345235,348513,351715,354971,358198,361407,364685,367900,371131,374362,377574,380800,383979,387202,390378,393606,396826,399993,403204,406429,409672,412849,416040,419246,422449,425648,428816,432073,435265,438410,441562,444757,447955,451159,454337,457497,460707,463872,467055,470283,473470,476648,479864,483015,486167,489319,492494,495666,498797,501962,505147,508261,511417,514565,517740,520910,524026,527154,530334,533506,536652,539777,542898,546024,549150,552319,555479,558597,561766,564877,567967,571119,574274,577439,580566,583714,586850,590006,593112,596222,599355,602489,605556,608672,611788,614917,618057,621177,624298,627400,630495,633578,636697,639851,642962,646054,649175,652265,655355,658445,661520,664579,667709,670820,673927,676970,680063,683178,686262,689382,692486,695609,698703,701795,704895,708007,711108,714154,717257,720341,723457,726517,729577,732707,735767,738873,741941,745001,748066,751131,754189,757288,760391,763455,766554,769639,772706,775773,778818,781906,784991,788060,791111,794149,797261,800285,803358,806435,809487,812601,815674,818703,821750,824801,827884,830940,834026,837099,840169,843192,846205,849252,852291,855281,858338,861401,864446,867482,870532,873606,876616,879640,882652,885698,888762,891833,894877,897938,900996,904057,907101,910077,913098,916147,919203,922193,925237,928293,931330,934441,937446,940455,943484,946551,949506,952566,955599,958651,961694,964695,967720,970704,973739,976761,979764,982776,985807,988851,991880,994839,997817,1000862,1003926,1006966,1009985,1013012,1016026,1019012,1022057,1025092,1028089,1031130,1034115,1037119,1040144,1043113,1046152,1049172,1052140,1055139,1058173,1061198,1064162,1067185,1070198,1073198,1076221,1079266,1082255,1085243,1088266,1091314,1094330,1097360,1100328,1103258,1106267,1109288,1112328,1115323,1118354,1121389,1124405,1127407,1130388,1133364,1136320,1139344,1142298,1145305,1148316,1151367,1154307,1157275,1160273,1163205,1166251,1169267,1172264,1175214,1178218,1181158,1184128,1187148,1190171,1193122,1196133,1199102,1202080,1205065,1208078,1211050,1214027,1216988,1219966,1222953,1225900,1228861,1231859,1234873,1237894,1240833,1243787,1246718,1249710,1252693,1255682,1258685,1261660,1264617,1267631,1270607,1273599,1276577,1279531,1282513,1285456,1288409,1291373,1294356,1297270,1300243,1303229,1306226,1309152,1312179,1315161,1318125,1321065,1324046,1326975,1329943,1332935,1335881,1338865,1341795,1344716,1347749,1350691,1353661,1356600,1359631,1362538,1365511,1368447,1371432,1374421,1377385,1380343,1383291,1386325,1389261,1392272,1395148,1398094,1401007,1403922,1406874,1409821,1412758,1415679,1418640,1421620,1424606,1427535,1430531,1433481,1436398,1439367,1442335,1445279,1448221,1451219,1454144,1457067,1460019,1462950,1465935,1468883,1471822,1474757,1477731,1480683,1483609,1486531,1489509,1492408,1495350,1498253,1501220,1504189,1507122,1510064,1512992,1515935,1518898,1521859,1524831,1527768,1530729,1533657,1536569,1539541,1542459,1545372,1548366,1551302,1554245,1557132,1560093,1562976,1565927,1568845,1571812,1574749,1577649,1580509,1583439,1586387,1589324,1592219,1595177,1598118,1601049,1603985,1606876,1609825,1612775,1615749,1618668,1621590,1624527,1627444,1630379,1633312,1636202,1639094,1642052,1644964,1647911,1650840,1653807,1656761,1659690,1662600,1665517,1668413,1671330,1674240,1677200,1680120,1683065,1685964,1688960,1691876,1694762,1697663,1700558,1703469,1706405,1709342,1712204,1715158,1718134,1721034,1723913,1726899,1729764,1732641,1735590,1738531,1741430,1744400,1747297,1750204,1753058,1756025,1758964,1761886,1764767,1767691,1770613,1773526,1776430,1779363,1782260,1785173,1788065,1790930,1793863,1796762,1799676,1802593,1805472,1808374,1811272,1814112,1817102,1820026,1822944,1825792,1828703,1831616,1834530,1837416,1840359,1843275,1846115,1849029,1852006,1854941,1857859,1860788,1863719,1866645,1869536,1872441,1875367,1878295,1881199,1884021,1886923,1889855,1892785,1895702,1898632,1901520,1904396,1907306,1910248,1913136,1915979,1918857,1921714,1924643,1927488,1930397,1933290,1936209,1939089,1941982,1944833,1947684,1950638,1953525,1956440,1959308,1962184,1965111,1968015,1970912,1973815,1976668,1979564,1982509,1985372,1988254,1991162,1994051,1996958,1999823,2002749,2005638,2008561,2011422,2014337,2017231,2020103,2022944,2025864,2028764,2031667,2034522,2037385,2040293,2043192,2046087,2048989,2051891,2054802,2057701,2060577,2063430,2066324,2069193,2072084,2074966,2077862,2080771,2083678,2086529,2089379,2092244,2095092,2097961,2100791,2103648,2106544,2109362,2112215,2115089,2118001,2120897,2123788,2126637,2129473,2132329,2135232,2138061,2141013,2143883,2146775,2149635,2152470,2155359,2158233,2161146,2163998,2166906,2169775,2172667,2175518,2178423,2181266,2184161,2187043,2189920,2192806,2195671,2198505,2201356,2204262,2207150,2210026,2212915,2215731,2218609,2221543,2224435,2227279,2230137,2233036,2235899,2238778,2241626,2244473,2247300,2250226,2253061,2255897,2258731,2261623,2264514,2267395,2270349,2273189,2276042,2278857,2281732,2284633,2287447,2290350,2293262,2296101,2298985,2301840,2304721,2307562,2310419,2313254,2316107,2318966,2321832,2324728,2327619,2330509,2333367,2336299,2339147,2342005,2344890,2347727,2350582,2353448,2356279,2359142,2362051,2364953,2367814,2370696,2373590,2376402,2379261,2382120,2384990,2387828,2390737,2393630,2396534,2399359,2402242,2405101,2407984,2410827,2413749,2416624,2419434,2422305,2425151,2427981,2430806,2433654,2436487,2439371,2442235,2445078,2447902,2450819,2453695,2456577,2459382,2462273,2465109,2467902,2470746,2473603,2476509,2479409,2482267,2485075,2487886,2490756,2493597,2496476,2499337,2502205,2505030,2507850,2510721,2513534,2516394,2519246,2522092,2524898,2527696,2530575,2533422,2536286,2539186,2542018,2544808,2547620,2550462,2553305,2556175,2559020,2561921,2564807,2567637,2570490,2573319,2576200,2579019,2581841,2584684,2587550,2590386,2593245,2596089,2598870,2601721,2604535,2607331,2610226,2613067,2615907,2618758,2621566,2624440,2627281,2630152,2632997,2635866,2638710,2641508,2644301,2647127,2649982,2652825,2655643,2658487,2661384,2664228,2667036,2669841,2672702,2675523,2678429,2681216,2684053,2686906,2689717,2692570,2695450,2698298,2701159,2703995,2706858,2709644,2712494,2715332,2718160,2721011,2723886,2726718,2729508,2732389,2735255,2738140,2740985,2743838,2746679,2749526,2752380,2755215,2758056,2760896,2763691,2766522,2769407,2772249,2775053,2777902,2780731,2783526,2786355,2789189,2791974,2794837,2797652,2800483,2803324,2806163,2808976,2811853,2814698,2817518,2820355,2823178,2826040,2828852,2831693,2834491,2837271,2840147,2842995,2845792,2848642,2851461,2854302,2857087,2859963,2862777,2865596,2868399,2871207,2874012,2876824,2879677,2882545,2885338,2888144,2890939,2893763,2896598,2899408,2902191,2905025,2907902,2910714,2913488,2916338,2919190,2921977,2924773,2927626,2930404,2933208,2936067,2938896,2941732,2944531,2947349,2950188,2952990,2955834,2958685,2961491,2964316,2967186,2970001,2972862,2975681,2978556,2981364,2984185,2987006,2989825,2992648,2995509,2998299};
bool prime[60000],seive[60000];
void seg_seive(int L,int R)   //区间筛法
{
    int len=R-L+1;
    for(int i=0; i<len; i++) prime[i]=1;
    if(1-L>=0) prime[1-L]=0;   //易错因为1不是素数也不是合数，这也是区间筛的一个易错bug
    for(int i=2; i*i<=R ; i++)
    {
        if(seive[i])
        {
            for(int j=max(2,(L-1+i)/i)*i; j<=R; j+=i) //第二个易错点，j必须从大于1，因为L可能小于i，但是seive[i]是素数。
                prime[j-L]=false;

        }

    }

}

int main()
{
    for(int i=2; i<50001; i++) seive[i]=1;
    for(int i=2; i*i<50001; i++) //预处理
        if(seive[i])
            for(int j=2*i; j<50001; j+=i)
                seive[j]=false;
    int n,rl=1;
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        int l=0,r=1000;
        while(l+1<r)
        {
            int mid=(l+r)/2;
            if(pos[mid]<n)
                l=mid;
            else r=mid;

        }
        int left=l*50000,right=r*50000;

        int x=n-pos[l];
        seg_seive(left,right);
        //printf("%d %d %d\n",left,right,x);
        for(int i=left; i<=right; i++)
        {
            if(prime[i-left]==1)
            {
                x--;
                if(x==0)
                {printf("Case %d: %d\n",rl++,i);break;}
            }
        }
    }
}