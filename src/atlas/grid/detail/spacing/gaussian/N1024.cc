/*
 * (C) Copyright 2013 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

// TL2047

#include "atlas/grid/detail/spacing/gaussian/N.h"

namespace atlas {
namespace grid {
namespace spacing {
namespace gaussian {

DEFINE_GAUSSIAN_LATITUDES(
    1024, LIST( 89.932737928460, 89.845605479540, 89.757958466419, 89.670195191296, 89.582387815250, 89.494559098662,
                89.406718455753, 89.318870478120, 89.231017670122, 89.143161513177, 89.055302939412, 88.967442564544,
                88.879580811588, 88.791717980751, 88.703854290968, 88.615989905657, 88.528124949263, 88.440259518219,
                88.352393688409, 88.264527520359, 88.176661062939, 88.088794356040, 88.000927432542, 87.913060319791,
                87.825193040716, 87.737325614688, 87.649458058179, 87.561590385292, 87.473722608166, 87.385854737308,
                87.297986781862, 87.210118749818, 87.122250648189, 87.034382483161, 86.946514260205, 86.858645984181,
                86.770777659421, 86.682909289796, 86.595040878780, 86.507172429496, 86.419303944761, 86.331435427121,
                86.243566878886, 86.155698302153, 86.067829698833, 85.979961070667, 85.892092419252, 85.804223746047,
                85.716355052393, 85.628486339523, 85.540617608572, 85.452748860590, 85.364880096544, 85.277011317330,
                85.189142523781, 85.101273716667, 85.013404896705, 84.925536064563, 84.837667220863, 84.749798366184,
                84.661929501069, 84.574060626026, 84.486191741528, 84.398322848020, 84.310453945921, 84.222585035621,
                84.134716117490, 84.046847191874, 83.958978259099, 83.871109319475, 83.783240373290, 83.695371420820,
                83.607502462324, 83.519633498046, 83.431764528220, 83.343895553063, 83.256026572786, 83.168157587584,
                83.080288597647, 82.992419603152, 82.904550604269, 82.816681601158, 82.728812593972, 82.640943582859,
                82.553074567956, 82.465205549396, 82.377336527307, 82.289467501807, 82.201598473014, 82.113729441036,
                82.025860405980, 81.937991367945, 81.850122327028, 81.762253283322, 81.674384236914, 81.586515187890,
                81.498646136330, 81.410777082312, 81.322908025911, 81.235038967199, 81.147169906244, 81.059300843113,
                80.971431777869, 80.883562710572, 80.795693641283, 80.707824570058, 80.619955496950, 80.532086422013,
                80.444217345296, 80.356348266849, 80.268479186718, 80.180610104949, 80.092741021585, 80.004871936668,
                79.917002850239, 79.829133762336, 79.741264672999, 79.653395582263, 79.565526490164, 79.477657396735,
                79.389788302011, 79.301919206022, 79.214050108800, 79.126181010375, 79.038311910775, 78.950442810029,
                78.862573708164, 78.774704605205, 78.686835501180, 78.598966396111, 78.511097290023, 78.423228182940,
                78.335359074884, 78.247489965876, 78.159620855938, 78.071751745091, 77.983882633354, 77.896013520746,
                77.808144407288, 77.720275292996, 77.632406177888, 77.544537061983, 77.456667945296, 77.368798827844,
                77.280929709643, 77.193060590708, 77.105191471054, 77.017322350696, 76.929453229649, 76.841584107925,
                76.753714985538, 76.665845862502, 76.577976738829, 76.490107614531, 76.402238489621, 76.314369364111,
                76.226500238012, 76.138631111335, 76.050761984091, 75.962892856291, 75.875023727945, 75.787154599064,
                75.699285469656, 75.611416339733, 75.523547209302, 75.435678078374, 75.347808946958, 75.259939815061,
                75.172070682693, 75.084201549862, 74.996332416576, 74.908463282843, 74.820594148671, 74.732725014067,
                74.644855879040, 74.556986743595, 74.469117607740, 74.381248471483, 74.293379334829, 74.205510197785,
                74.117641060359, 74.029771922556, 73.941902784382, 73.854033645844, 73.766164506947, 73.678295367697,
                73.590426228100, 73.502557088162, 73.414687947887, 73.326818807282, 73.238949666350, 73.151080525099,
                73.063211383532, 72.975342241654, 72.887473099470, 72.799603956985, 72.711734814204, 72.623865671130,
                72.535996527769, 72.448127384125, 72.360258240201, 72.272389096003, 72.184519951533, 72.096650806797,
                72.008781661798, 71.920912516539, 71.833043371026, 71.745174225260, 71.657305079247, 71.569435932989,
                71.481566786490, 71.393697639753, 71.305828492782, 71.217959345580, 71.130090198151, 71.042221050496,
                70.954351902621, 70.866482754527, 70.778613606218, 70.690744457696, 70.602875308964, 70.515006160026,
                70.427137010884, 70.339267861541, 70.251398711999, 70.163529562262, 70.075660412331, 69.987791262209,
                69.899922111899, 69.812052961404, 69.724183810725, 69.636314659865, 69.548445508827, 69.460576357612,
                69.372707206223, 69.284838054662, 69.196968902932, 69.109099751034, 69.021230598970, 68.933361446744,
                68.845492294356, 68.757623141808, 68.669753989104, 68.581884836244, 68.494015683230, 68.406146530065,
                68.318277376750, 68.230408223287, 68.142539069678, 68.054669915925, 67.966800762029, 67.878931607992,
                67.791062453816, 67.703193299502, 67.615324145052, 67.527454990468, 67.439585835750, 67.351716680902,
                67.263847525924, 67.175978370817, 67.088109215584, 67.000240060226, 66.912370904743, 66.824501749138,
                66.736632593412, 66.648763437566, 66.560894281602, 66.473025125521, 66.385155969324, 66.297286813013,
                66.209417656589, 66.121548500052, 66.033679343405, 65.945810186649, 65.857941029784, 65.770071872812,
                65.682202715735, 65.594333558552, 65.506464401266, 65.418595243877, 65.330726086387, 65.242856928797,
                65.154987771107, 65.067118613319, 64.979249455434, 64.891380297453, 64.803511139377, 64.715641981206,
                64.627772822942, 64.539903664587, 64.452034506139, 64.364165347602, 64.276296188975, 64.188427030260,
                64.100557871457, 64.012688712568, 63.924819553592, 63.836950394532, 63.749081235388, 63.661212076161,
                63.573342916851, 63.485473757459, 63.397604597987, 63.309735438435, 63.221866278804, 63.133997119094,
                63.046127959307, 62.958258799443, 62.870389639503, 62.782520479487, 62.694651319397, 62.606782159233,
                62.518912998996, 62.431043838687, 62.343174678305, 62.255305517853, 62.167436357330, 62.079567196737,
                61.991698036075, 61.903828875345, 61.815959714547, 61.728090553681, 61.640221392750, 61.552352231752,
                61.464483070689, 61.376613909561, 61.288744748369, 61.200875587114, 61.113006425796, 61.025137264415,
                60.937268102973, 60.849398941469, 60.761529779905, 60.673660618281, 60.585791456597, 60.497922294854,
                60.410053133052, 60.322183971193, 60.234314809276, 60.146445647302, 60.058576485271, 59.970707323185,
                59.882838161043, 59.794968998847, 59.707099836595, 59.619230674290, 59.531361511931, 59.443492349520,
                59.355623187055, 59.267754024539, 59.179884861970, 59.092015699351, 59.004146536680, 58.916277373959,
                58.828408211189, 58.740539048368, 58.652669885499, 58.564800722581, 58.476931559614, 58.389062396600,
                58.301193233538, 58.213324070430, 58.125454907274, 58.037585744072, 57.949716580824, 57.861847417531,
                57.773978254193, 57.686109090809, 57.598239927382, 57.510370763910, 57.422501600395, 57.334632436836,
                57.246763273234, 57.158894109590, 57.071024945903, 56.983155782175, 56.895286618404, 56.807417454593,
                56.719548290741, 56.631679126848, 56.543809962914, 56.455940798941, 56.368071634928, 56.280202470876,
                56.192333306784, 56.104464142654, 56.016594978486, 55.928725814279, 55.840856650035, 55.752987485753,
                55.665118321433, 55.577249157077, 55.489379992684, 55.401510828255, 55.313641663790, 55.225772499289,
                55.137903334752, 55.050034170180, 54.962165005573, 54.874295840932, 54.786426676256, 54.698557511545,
                54.610688346801, 54.522819182023, 54.434950017212, 54.347080852367, 54.259211687489, 54.171342522579,
                54.083473357636, 53.995604192661, 53.907735027655, 53.819865862616, 53.731996697546, 53.644127532444,
                53.556258367312, 53.468389202149, 53.380520036955, 53.292650871731, 53.204781706476, 53.116912541192,
                53.029043375878, 52.941174210535, 52.853305045162, 52.765435879760, 52.677566714330, 52.589697548871,
                52.501828383383, 52.413959217867, 52.326090052323, 52.238220886751, 52.150351721152, 52.062482555525,
                51.974613389871, 51.886744224189, 51.798875058481, 51.711005892747, 51.623136726985, 51.535267561198,
                51.447398395384, 51.359529229545, 51.271660063679, 51.183790897788, 51.095921731872, 51.008052565931,
                50.920183399964, 50.832314233973, 50.744445067957, 50.656575901916, 50.568706735851, 50.480837569762,
                50.392968403648, 50.305099237511, 50.217230071350, 50.129360905166, 50.041491738958, 49.953622572727,
                49.865753406473, 49.777884240196, 49.690015073896, 49.602145907574, 49.514276741229, 49.426407574862,
                49.338538408472, 49.250669242061, 49.162800075628, 49.074930909173, 48.987061742696, 48.899192576198,
                48.811323409679, 48.723454243139, 48.635585076577, 48.547715909995, 48.459846743392, 48.371977576768,
                48.284108410124, 48.196239243460, 48.108370076775, 48.020500910070, 47.932631743346, 47.844762576601,
                47.756893409837, 47.669024243053, 47.581155076250, 47.493285909427, 47.405416742586, 47.317547575725,
                47.229678408845, 47.141809241947, 47.053940075030, 46.966070908094, 46.878201741140, 46.790332574167,
                46.702463407176, 46.614594240167, 46.526725073140, 46.438855906096, 46.350986739033, 46.263117571953,
                46.175248404855, 46.087379237740, 45.999510070607, 45.911640903457, 45.823771736290, 45.735902569106,
                45.648033401905, 45.560164234688, 45.472295067453, 45.384425900202, 45.296556732935, 45.208687565651,
                45.120818398351, 45.032949231035, 44.945080063702, 44.857210896354, 44.769341728989, 44.681472561609,
                44.593603394213, 44.505734226802, 44.417865059375, 44.329995891933, 44.242126724475, 44.154257557002,
                44.066388389514, 43.978519222011, 43.890650054493, 43.802780886960, 43.714911719412, 43.627042551849,
                43.539173384272, 43.451304216681, 43.363435049075, 43.275565881454, 43.187696713820, 43.099827546171,
                43.011958378508, 42.924089210831, 42.836220043140, 42.748350875436, 42.660481707717, 42.572612539985,
                42.484743372240, 42.396874204480, 42.309005036708, 42.221135868922, 42.133266701123, 42.045397533310,
                41.957528365484, 41.869659197646, 41.781790029794, 41.693920861930, 41.606051694052, 41.518182526162,
                41.430313358259, 41.342444190344, 41.254575022416, 41.166705854475, 41.078836686523, 40.990967518558,
                40.903098350580, 40.815229182591, 40.727360014589, 40.639490846575, 40.551621678550, 40.463752510512,
                40.375883342463, 40.288014174402, 40.200145006329, 40.112275838244, 40.024406670148, 39.936537502041,
                39.848668333922, 39.760799165792, 39.672929997650, 39.585060829497, 39.497191661333, 39.409322493158,
                39.321453324972, 39.233584156775, 39.145714988566, 39.057845820347, 38.969976652118, 38.882107483877,
                38.794238315626, 38.706369147364, 38.618499979092, 38.530630810809, 38.442761642515, 38.354892474212,
                38.267023305898, 38.179154137573, 38.091284969239, 38.003415800894, 37.915546632539, 37.827677464174,
                37.739808295800, 37.651939127415, 37.564069959020, 37.476200790616, 37.388331622201, 37.300462453777,
                37.212593285344, 37.124724116900, 37.036854948448, 36.948985779985, 36.861116611513, 36.773247443032,
                36.685378274542, 36.597509106042, 36.509639937533, 36.421770769014, 36.333901600487, 36.246032431950,
                36.158163263405, 36.070294094850, 35.982424926287, 35.894555757714, 35.806686589133, 35.718817420543,
                35.630948251944, 35.543079083336, 35.455209914720, 35.367340746095, 35.279471577462, 35.191602408820,
                35.103733240170, 35.015864071511, 34.927994902843, 34.840125734168, 34.752256565484, 34.664387396792,
                34.576518228092, 34.488649059383, 34.400779890666, 34.312910721942, 34.225041553209, 34.137172384468,
                34.049303215720, 33.961434046963, 33.873564878199, 33.785695709426, 33.697826540646, 33.609957371859,
                33.522088203063, 33.434219034260, 33.346349865450, 33.258480696631, 33.170611527805, 33.082742358972,
                32.994873190131, 32.907004021283, 32.819134852428, 32.731265683565, 32.643396514695, 32.555527345817,
                32.467658176933, 32.379789008041, 32.291919839142, 32.204050670236, 32.116181501323, 32.028312332403,
                31.940443163476, 31.852573994542, 31.764704825601, 31.676835656653, 31.588966487698, 31.501097318737,
                31.413228149768, 31.325358980793, 31.237489811812, 31.149620642823, 31.061751473829, 30.973882304827,
                30.886013135819, 30.798143966804, 30.710274797783, 30.622405628756, 30.534536459722, 30.446667290681,
                30.358798121634, 30.270928952581, 30.183059783522, 30.095190614457, 30.007321445385, 29.919452276307,
                29.831583107223, 29.743713938132, 29.655844769036, 29.567975599934, 29.480106430825, 29.392237261711,
                29.304368092591, 29.216498923464, 29.128629754332, 29.040760585194, 28.952891416050, 28.865022246901,
                28.777153077745, 28.689283908584, 28.601414739417, 28.513545570245, 28.425676401067, 28.337807231883,
                28.249938062693, 28.162068893498, 28.074199724298, 27.986330555092, 27.898461385880, 27.810592216664,
                27.722723047441, 27.634853878214, 27.546984708981, 27.459115539742, 27.371246370498, 27.283377201249,
                27.195508031995, 27.107638862736, 27.019769693471, 26.931900524202, 26.844031354927, 26.756162185647,
                26.668293016362, 26.580423847071, 26.492554677776, 26.404685508476, 26.316816339171, 26.228947169861,
                26.141078000546, 26.053208831226, 25.965339661902, 25.877470492572, 25.789601323238, 25.701732153899,
                25.613862984555, 25.525993815206, 25.438124645853, 25.350255476495, 25.262386307132, 25.174517137765,
                25.086647968393, 24.998778799016, 24.910909629635, 24.823040460250, 24.735171290859, 24.647302121465,
                24.559432952066, 24.471563782662, 24.383694613254, 24.295825443842, 24.207956274425, 24.120087105005,
                24.032217935579, 23.944348766150, 23.856479596716, 23.768610427278, 23.680741257835, 23.592872088389,
                23.505002918938, 23.417133749483, 23.329264580024, 23.241395410561, 23.153526241094, 23.065657071623,
                22.977787902148, 22.889918732668, 22.802049563185, 22.714180393698, 22.626311224207, 22.538442054711,
                22.450572885212, 22.362703715710, 22.274834546203, 22.186965376692, 22.099096207178, 22.011227037659,
                21.923357868137, 21.835488698612, 21.747619529082, 21.659750359549, 21.571881190012, 21.484012020472,
                21.396142850927, 21.308273681379, 21.220404511828, 21.132535342273, 21.044666172714, 20.956797003152,
                20.868927833587, 20.781058664017, 20.693189494445, 20.605320324869, 20.517451155289, 20.429581985706,
                20.341712816120, 20.253843646530, 20.165974476937, 20.078105307340, 19.990236137740, 19.902366968137,
                19.814497798531, 19.726628628921, 19.638759459308, 19.550890289692, 19.463021120072, 19.375151950450,
                19.287282780824, 19.199413611195, 19.111544441563, 19.023675271928, 18.935806102290, 18.847936932648,
                18.760067763004, 18.672198593357, 18.584329423706, 18.496460254053, 18.408591084396, 18.320721914737,
                18.232852745075, 18.144983575409, 18.057114405741, 17.969245236070, 17.881376066396, 17.793506896719,
                17.705637727039, 17.617768557357, 17.529899387672, 17.442030217984, 17.354161048293, 17.266291878599,
                17.178422708903, 17.090553539204, 17.002684369502, 16.914815199797, 16.826946030090, 16.739076860380,
                16.651207690668, 16.563338520953, 16.475469351235, 16.387600181515, 16.299731011792, 16.211861842067,
                16.123992672339, 16.036123502609, 15.948254332876, 15.860385163141, 15.772515993403, 15.684646823662,
                15.596777653920, 15.508908484175, 15.421039314427, 15.333170144677, 15.245300974925, 15.157431805170,
                15.069562635413, 14.981693465654, 14.893824295893, 14.805955126129, 14.718085956363, 14.630216786594,
                14.542347616824, 14.454478447051, 14.366609277276, 14.278740107498, 14.190870937719, 14.103001767937,
                14.015132598154, 13.927263428368, 13.839394258580, 13.751525088790, 13.663655918998, 13.575786749203,
                13.487917579407, 13.400048409609, 13.312179239809, 13.224310070006, 13.136440900202, 13.048571730396,
                12.960702560587, 12.872833390777, 12.784964220965, 12.697095051151, 12.609225881335, 12.521356711517,
                12.433487541698, 12.345618371876, 12.257749202053, 12.169880032227, 12.082010862400, 11.994141692572,
                11.906272522741, 11.818403352909, 11.730534183074, 11.642665013239, 11.554795843401, 11.466926673562,
                11.379057503721, 11.291188333878, 11.203319164034, 11.115449994188, 11.027580824340, 10.939711654491,
                10.851842484640, 10.763973314787, 10.676104144933, 10.588234975078, 10.500365805220, 10.412496635362,
                10.324627465501, 10.236758295640, 10.148889125776, 10.061019955912, 9.973150786046, 9.885281616178,
                9.797412446309, 9.709543276438, 9.621674106566, 9.533804936693, 9.445935766818, 9.358066596942,
                9.270197427065, 9.182328257186, 9.094459087306, 9.006589917424, 8.918720747542, 8.830851577657,
                8.742982407772, 8.655113237886, 8.567244067998, 8.479374898109, 8.391505728218, 8.303636558327,
                8.215767388434, 8.127898218540, 8.040029048645, 7.952159878749, 7.864290708852, 7.776421538953,
                7.688552369054, 7.600683199153, 7.512814029251, 7.424944859348, 7.337075689444, 7.249206519539,
                7.161337349633, 7.073468179726, 6.985599009818, 6.897729839909, 6.809860669999, 6.721991500088,
                6.634122330176, 6.546253160263, 6.458383990349, 6.370514820434, 6.282645650519, 6.194776480602,
                6.106907310685, 6.019038140766, 5.931168970847, 5.843299800927, 5.755430631006, 5.667561461084,
                5.579692291162, 5.491823121239, 5.403953951315, 5.316084781390, 5.228215611464, 5.140346441538,
                5.052477271611, 4.964608101683, 4.876738931755, 4.788869761826, 4.701000591896, 4.613131421965,
                4.525262252034, 4.437393082102, 4.349523912170, 4.261654742237, 4.173785572303, 4.085916402369,
                3.998047232434, 3.910178062499, 3.822308892563, 3.734439722626, 3.646570552689, 3.558701382752,
                3.470832212814, 3.382963042876, 3.295093872937, 3.207224702997, 3.119355533057, 3.031486363117,
                2.943617193176, 2.855748023235, 2.767878853294, 2.680009683352, 2.592140513409, 2.504271343467,
                2.416402173524, 2.328533003580, 2.240663833637, 2.152794663692, 2.064925493748, 1.977056323804,
                1.889187153859, 1.801317983914, 1.713448813968, 1.625579644023, 1.537710474077, 1.449841304131,
                1.361972134184, 1.274102964238, 1.186233794291, 1.098364624344, 1.010495454397, 0.922626284450,
                0.834757114503, 0.746887944556, 0.659018774608, 0.571149604661, 0.483280434713, 0.395411264765,
                0.307542094817, 0.219672924870, 0.131803754922, 0.043934584974 ) )

}  // namespace gaussian
}  // namespace spacing
}  // namespace grid
}  // namespace atlas
