struct data_t {
	Int_t type, idx, nrows, barrel, layer, ladder, wafer, hybrid, Npar;
	Double_t v0, v1, v2, v3, v4, v5;
	Char_t Comment[10];
};
data_t Data[] = {
	{2,0,0,1,2, 1, 1, 1, 0,-0.00032, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2101"},
	{2,0,0,1,2, 1, 1, 2, 0,-0.00940, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2101"},
	{2,0,0,1,2, 1, 2, 1, 0, 0.01206, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2201"},
	{2,0,0,1,2, 1, 2, 2, 0,-0.03277, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2201"},
	{2,0,0,1,2, 1, 4, 1, 3,-0.03027, 0.00000, 0.01223,-0.00710, 0.00000, 0.00000,"duuH2401"},
	{2,0,0,1,2, 1, 4, 2, 0, 0.03909, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2401"},
	{2,0,0,1,1, 2, 1, 1, 1,-0.01982,-0.00560, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1102"},
	{2,0,0,1,1, 2, 1, 2, 1, 0.04206,-0.01354, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1102"},
	{2,0,0,1,1, 2, 2, 1, 1,-0.01450,-0.00674, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1202"},
	{2,0,0,1,1, 2, 2, 2, 1, 0.04851,-0.01317, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1202"},
	{2,0,0,1,1, 2, 3, 1, 2,-0.01789,-0.01914,-0.00132, 0.00000, 0.00000, 0.00000,"duuH1302"},
	{2,0,0,1,1, 2, 3, 2, 1, 0.01021, 0.01243, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1302"},
	{2,0,0,1,1, 2, 4, 1, 2,-0.01985,-0.01856, 0.00139, 0.00000, 0.00000, 0.00000,"duuH1402"},
	{2,0,0,1,1, 2, 4, 2, 1, 0.01898, 0.01707, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1402"},
	{2,0,0,1,2, 3, 1, 1, 4,-0.01196, 0.00000, 0.01934,-0.01239, 0.01043, 0.00000,"duuH2103"},
	{2,0,0,1,2, 3, 1, 2, 3,-0.11604, 0.00000, 0.00000, 0.00998, 0.00000, 0.00000,"duuH2103"},
	{2,0,0,1,2, 3, 2, 1, 5, 0.03284,-0.03873, 0.00000,-0.02299, 0.00000,-0.00978,"duuH2203"},
	{2,0,0,1,2, 3, 3, 1, 3, 0.04853,-0.02062,-0.01246,-0.01287, 0.00000, 0.00000,"duuH2303"},
	{2,0,0,1,2, 3, 3, 2, 2, 0.01808, 0.00000, 0.01046, 0.00000, 0.00000, 0.00000,"duuH2303"},
	{2,0,0,1,2, 3, 4, 1, 2, 0.05311,-0.02661,-0.01137, 0.00000, 0.00000, 0.00000,"duuH2403"},
	{2,0,0,1,2, 3, 4, 2, 2, 0.08774, 0.01777, 0.01120, 0.00000, 0.00000, 0.00000,"duuH2403"},
	{2,0,0,1,1, 4, 1, 1, 5, 0.09099,-0.00495, 0.00000,-0.03973, 0.00000,-0.02208,"duuH1104"},
	{2,0,0,1,1, 4, 1, 2, 5,-0.12080, 0.00000, 0.00000, 0.03044, 0.00000, 0.01862,"duuH1104"},
	{2,0,0,1,1, 4, 2, 1, 2, 0.00546,-0.06103,-0.03790, 0.00000, 0.00000, 0.00000,"duuH1204"},
	{2,0,0,1,1, 4, 2, 2, 5,-0.05413, 0.00000, 0.00000, 0.02307, 0.00000, 0.01611,"duuH1204"},
	{2,0,0,1,1, 4, 3, 1, 3, 0.04127, 0.00000, 0.00000,-0.01866, 0.00000, 0.00000,"duuH1304"},
	{2,0,0,1,1, 4, 3, 2, 3, 0.00449, 0.06420, 0.00000, 0.02815, 0.00000, 0.00000,"duuH1304"},
	{2,0,0,1,1, 4, 4, 1, 5, 0.04089, 0.00000, 0.00000, 0.00000, 0.00000, 0.01590,"duuH1404"},
	{2,0,0,1,1, 4, 4, 2, 3, 0.11279, 0.04940, 0.00000, 0.01951, 0.00000, 0.00000,"duuH1404"},
	{2,0,0,1,2, 5, 1, 1, 2,-0.01865,-0.01384,-0.00277, 0.00000, 0.00000, 0.00000,"duuH2105"},
	{2,0,0,1,2, 5, 1, 2, 5, 0.00879, 0.01577, 0.00391, 0.00000, 0.00000, 0.00133,"duuH2105"},
	{2,0,0,1,2, 5, 2, 1, 2,-0.01959,-0.01393,-0.00489, 0.00000, 0.00000, 0.00000,"duuH2205"},
	{2,0,0,1,2, 5, 2, 2, 5, 0.00989, 0.01442, 0.00382, 0.00000, 0.00000, 0.00161,"duuH2205"},
	{2,0,0,1,2, 5, 3, 1, 3,-0.02033,-0.01464,-0.00083,-0.00110, 0.00000, 0.00000,"duuH2305"},
	{2,0,0,1,2, 5, 3, 2, 2, 0.01072, 0.01794, 0.00190, 0.00000, 0.00000, 0.00000,"duuH2305"},
	{2,0,0,1,2, 5, 4, 1, 3,-0.02229,-0.01523, 0.00000,-0.00139, 0.00000, 0.00000,"duuH2405"},
	{2,0,0,1,2, 5, 4, 2, 2, 0.00988, 0.01862, 0.00300, 0.00000, 0.00000, 0.00000,"duuH2405"},
	{2,0,0,1,1, 6, 1, 1, 5,-0.01727, 0.00000, 0.00000,-0.00465, 0.00000,-0.00344,"duuH1106"},
	{2,0,0,1,1, 6, 1, 2, 2, 0.02335, 0.01887, 0.00219, 0.00000, 0.00000, 0.00000,"duuH1106"},
	{2,0,0,1,1, 6, 2, 1, 5,-0.00847, 0.00000, 0.00000,-0.00423, 0.00000,-0.00309,"duuH1206"},
	{2,0,0,1,1, 6, 2, 2, 2, 0.03225, 0.01898, 0.00222, 0.00000, 0.00000, 0.00000,"duuH1206"},
	{2,0,0,1,1, 6, 3, 1, 5, 0.01024,-0.01042,-0.00505, 0.00000, 0.00000,-0.00299,"duuH1306"},
	{2,0,0,1,1, 6, 3, 2, 4, 0.03975, 0.01772, 0.00265, 0.00000,-0.00272, 0.00000,"duuH1306"},
	{2,0,0,1,1, 6, 4, 1, 2, 0.01639,-0.01564,-0.00603, 0.00000, 0.00000, 0.00000,"duuH1406"},
	{2,0,0,1,1, 6, 4, 2, 2, 0.04145, 0.02051, 0.00388, 0.00000, 0.00000, 0.00000,"duuH1406"},
	{2,0,0,1,2, 7, 1, 1, 1,-0.03347,-0.01320, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2107"},
	{2,0,0,1,2, 7, 1, 2, 1,-0.00631, 0.01502, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2107"},
	{2,0,0,1,2, 7, 2, 1, 1,-0.02444,-0.01488, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2207"},
	{2,0,0,1,2, 7, 2, 2, 1, 0.00627, 0.01265, 0.00000, 0.00000, 0.00000, 0.00000,"duuH2207"},
	{2,0,0,1,2, 7, 3, 1, 5,-0.01685,-0.02049,-0.00623,-0.00361, 0.00000, 0.00240,"duuH2307"},
	{2,0,0,1,2, 7, 3, 2, 5, 0.01735, 0.01643, 0.00346, 0.00478, 0.00000,-0.00176,"duuH2307"},
	{2,0,0,1,2, 7, 4, 1, 3,-0.00929,-0.02105,-0.00687,-0.00508, 0.00000, 0.00000,"duuH2407"},
	{2,0,0,1,1, 8, 3, 1, 5,-0.02105,-0.00979, 0.00000, 0.00000, 0.00000,-0.00303,"duuH1308"},
	{2,0,0,1,1, 8, 3, 2, 1, 0.00953, 0.01777, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1308"},
	{2,0,0,1,1, 8, 4, 1, 5,-0.02366,-0.01275, 0.00000, 0.00000, 0.00000,-0.00186,"duuH1408"},
	{2,0,0,1,1, 8, 4, 2, 1, 0.01048, 0.01921, 0.00000, 0.00000, 0.00000, 0.00000,"duuH1408"},
	{2,0,0,2,4, 1, 1, 1, 2, 0.04493,-0.03772,-0.02919, 0.00000, 0.00000, 0.00000,"duuH4101"},
	{2,0,0,2,4, 1, 1, 2, 2,-0.02278, 0.06881, 0.02907, 0.00000, 0.00000, 0.00000,"duuH4101"},
	{2,0,0,2,4, 1, 2, 1, 2, 0.04972,-0.04004,-0.02980, 0.00000, 0.00000, 0.00000,"duuH4201"},
	{2,0,0,2,4, 1, 2, 2, 4, 0.01352, 0.03363, 0.01967, 0.00000,-0.01280, 0.00000,"duuH4201"},
	{2,0,0,2,4, 1, 3, 1, 2, 0.05536,-0.04555,-0.03042, 0.00000, 0.00000, 0.00000,"duuH4301"},
	{2,0,0,2,4, 1, 3, 2, 4, 0.01637, 0.03474, 0.02080, 0.00000,-0.01366, 0.00000,"duuH4301"},
	{2,0,0,2,3, 2, 1, 1, 5,-0.01518,-0.05455, 0.02929,-0.01219, 0.00000, 0.00499,"duuH3102"},
	{2,0,0,2,3, 2, 1, 2, 3,-0.03713, 0.06250,-0.03321, 0.01894, 0.00000, 0.00000,"duuH3102"},
	{2,0,0,2,3, 2, 2, 1, 3, 0.00718,-0.05666, 0.02710,-0.01519, 0.00000, 0.00000,"duuH3202"},
	{2,0,0,2,3, 2, 2, 2, 5,-0.01627, 0.05710,-0.02808, 0.01369, 0.00000,-0.00410,"duuH3202"},
	{2,0,0,2,3, 2, 3, 1, 3, 0.01834,-0.05752, 0.03157,-0.01793, 0.00000, 0.00000,"duuH3302"},
	{2,0,0,2,3, 2, 3, 2, 5, 0.00841, 0.05173,-0.03125, 0.01204, 0.00000,-0.00554,"duuH3302"},
	{2,0,0,2,3, 2, 4, 1, 3, 0.07891, 0.00000, 0.02207,-0.01094, 0.00000, 0.00000,"duuH3402"},
	{2,0,0,2,3, 2, 4, 2, 2,-0.01805, 0.00000,-0.02070, 0.00000, 0.00000, 0.00000,"duuH3402"},
	{2,0,0,2,3, 2, 5, 2, 3,-0.07480, 0.00000, 0.00000, 0.02136, 0.00000, 0.00000,"duuH3502"},
	{2,0,0,2,3, 2, 6, 2, 2, 0.01726,-0.00535, 0.05431, 0.00000, 0.00000, 0.00000,"duuH3602"},
	{2,0,0,2,4, 3, 1, 1, 2,-0.03360, 0.00000, 0.00136, 0.00000, 0.00000, 0.00000,"duuH4103"},
	{2,0,0,2,4, 3, 1, 2, 3, 0.00864, 0.00721, 0.00000, 0.00329, 0.00000, 0.00000,"duuH4103"},
	{2,0,0,2,4, 3, 2, 1, 1,-0.02543,-0.00827, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4203"},
	{2,0,0,2,4, 3, 2, 2, 3, 0.00790, 0.00548, 0.00000, 0.00315, 0.00000, 0.00000,"duuH4203"},
	{2,0,0,2,4, 3, 3, 1, 1,-0.02703,-0.00786, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4303"},
	{2,0,0,2,4, 3, 3, 2, 3, 0.00857, 0.00885, 0.00433, 0.00415, 0.00000, 0.00000,"duuH4303"},
	{2,0,0,2,4, 3, 4, 1, 4,-0.01645,-0.01316, 0.00000, 0.00000, 0.00080, 0.00000,"duuH4403"},
	{2,0,0,2,4, 3, 4, 2, 3, 0.00202, 0.01045, 0.00000, 0.00401, 0.00000, 0.00000,"duuH4403"},
	{2,0,0,2,4, 3, 5, 1, 1,-0.01770,-0.01357, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4503"},
	{2,0,0,2,4, 3, 5, 2, 3, 0.00326, 0.00957, 0.00000, 0.00392, 0.00000, 0.00000,"duuH4503"},
	{2,0,0,2,4, 3, 6, 1, 1, 0.01052, 0.00497, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4603"},
	{2,0,0,2,4, 3, 6, 2, 1,-0.02847,-0.00805, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4603"},
	{2,0,0,2,3, 4, 1, 1, 5,-0.01088, 0.00000, 0.00000,-0.00512, 0.00000,-0.00341,"duuH3104"},
	{2,0,0,2,3, 4, 1, 2, 0,-0.00632, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3104"},
	{2,0,0,2,3, 4, 2, 1, 0, 0.03770, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3204"},
	{2,0,0,2,3, 4, 2, 2, 0,-0.03879, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3204"},
	{2,0,0,2,3, 4, 3, 1, 0, 0.02801, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3304"},
	{2,0,0,2,3, 4, 3, 2, 1, 0.02326, 0.00950, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3304"},
	{2,0,0,2,3, 4, 4, 1, 1, 0.01269,-0.00590, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3404"},
	{2,0,0,2,3, 4, 4, 2, 1, 0.03635, 0.01591, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3404"},
	{2,0,0,2,3, 4, 5, 1, 1, 0.00857,-0.02099, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3504"},
	{2,0,0,2,3, 4, 5, 2, 4, 0.05025, 0.02072, 0.00000, 0.00000,-0.00246, 0.00000,"duuH3504"},
	{2,0,0,2,3, 4, 6, 1, 1, 0.02251,-0.02372, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3604"},
	{2,0,0,2,3, 4, 6, 2, 4, 0.06325, 0.01859, 0.00000, 0.00000,-0.00308, 0.00000,"duuH3604"},
	{2,0,0,2,4, 5, 1, 1, 1,-0.09719,-0.00745, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4105"},
	{2,0,0,2,4, 5, 1, 2, 0,-0.07079, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4105"},
	{2,0,0,2,4, 5, 2, 1, 2,-0.08703,-0.01176, 0.00408, 0.00000, 0.00000, 0.00000,"duuH4205"},
	{2,0,0,2,4, 5, 2, 2, 4,-0.04678, 0.01602, 0.00616, 0.00000, 0.00391, 0.00000,"duuH4205"},
	{2,0,0,2,4, 5, 3, 1, 1,-0.07051,-0.01190, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4305"},
	{2,0,0,2,4, 5, 3, 2, 4,-0.02502, 0.00874, 0.00679, 0.00000, 0.00391, 0.00000,"duuH4305"},
	{2,0,0,2,4, 5, 4, 1, 0,-0.06791, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4405"},
	{2,0,0,2,4, 5, 4, 2, 0,-0.00815, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4405"},
	{2,0,0,2,4, 5, 5, 1, 0,-0.05779, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4505"},
	{2,0,0,2,4, 5, 5, 2, 0, 0.01605, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4505"},
	{2,0,0,2,4, 5, 6, 1, 0,-0.03968, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4605"},
	{2,0,0,2,4, 5, 6, 2, 0, 0.03985, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4605"},
	{2,0,0,2,3, 6, 1, 1, 5, 0.01219, 0.00000, 0.00000,-0.01351, 0.00000,-0.00633,"duuH3106"},
	{2,0,0,2,3, 6, 1, 2, 1, 0.03889,-0.01102, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3106"},
	{2,0,0,2,3, 6, 2, 1, 3, 0.00601, 0.00000, 0.00000,-0.00881, 0.00000, 0.00000,"duuH3206"},
	{2,0,0,2,3, 6, 2, 2, 3, 0.04340, 0.00000, 0.00000, 0.00689, 0.00000, 0.00000,"duuH3206"},
	{2,0,0,2,3, 6, 3, 1, 3,-0.00282, 0.00000, 0.00000,-0.00646, 0.00000, 0.00000,"duuH3306"},
	{2,0,0,2,3, 6, 3, 2, 4, 0.04665, 0.00000, 0.00000, 0.00000,-0.00595, 0.00000,"duuH3306"},
	{2,0,0,2,3, 6, 4, 1, 0, 0.00556, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3406"},
	{2,0,0,2,3, 6, 4, 2, 0, 0.04351, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3406"},
	{2,0,0,2,3, 6, 5, 1, 3,-0.00156,-0.01874, 0.00000,-0.01135, 0.00000, 0.00000,"duuH3506"},
	{2,0,0,2,3, 6, 5, 2, 1, 0.04830, 0.01458, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3506"},
	{2,0,0,2,3, 6, 6, 1, 3,-0.01445,-0.02040, 0.00000,-0.01126, 0.00000, 0.00000,"duuH3606"},
	{2,0,0,2,3, 6, 6, 2, 1, 0.05861, 0.01298, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3606"},
	{2,0,0,2,4, 7, 1, 1, 1,-0.04101,-0.01314, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4107"},
	{2,0,0,2,4, 7, 1, 2, 2,-0.01200, 0.00784, 0.00327, 0.00000, 0.00000, 0.00000,"duuH4107"},
	{2,0,0,2,4, 7, 2, 1, 3,-0.02244,-0.01008, 0.00000,-0.00213, 0.00000, 0.00000,"duuH4207"},
	{2,0,0,2,4, 7, 2, 2, 3, 0.00661, 0.00753, 0.00298, 0.00248, 0.00000, 0.00000,"duuH4207"},
	{2,0,0,2,4, 7, 3, 1, 3,-0.00629,-0.01476, 0.00000,-0.00206, 0.00000, 0.00000,"duuH4307"},
	{2,0,0,2,4, 7, 3, 2, 2, 0.02552, 0.00771, 0.00253, 0.00000, 0.00000, 0.00000,"duuH4307"},
	{2,0,0,2,4, 7, 4, 1, 3, 0.01623,-0.01704, 0.00000,-0.00287, 0.00000, 0.00000,"duuH4407"},
	{2,0,0,2,4, 7, 4, 2, 1, 0.04070, 0.01915, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4407"},
	{2,0,0,2,4, 7, 5, 1, 3, 0.02932,-0.02001, 0.00000,-0.00292, 0.00000, 0.00000,"duuH4507"},
	{2,0,0,2,4, 7, 5, 2, 1, 0.05939, 0.01305, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4507"},
	{2,0,0,2,4, 7, 6, 1, 1, 0.04497,-0.02211, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4607"},
	{2,0,0,2,4, 7, 6, 2, 1, 0.07671, 0.01749, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4607"},
	{2,0,0,2,3, 8, 4, 1, 0,-0.02044, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3408"},
	{2,0,0,2,3, 8, 4, 2, 0, 0.05031, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3408"},
	{2,0,0,2,3, 8, 5, 1, 3,-0.00263, 0.00000, 0.00000,-0.00910, 0.00000, 0.00000,"duuH3508"},
	{2,0,0,2,3, 8, 5, 2, 0, 0.06564, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH3508"},
	{2,0,0,2,3, 8, 6, 1, 3, 0.00635, 0.00000, 0.00000,-0.01091, 0.00000, 0.00000,"duuH3608"},
	{2,0,0,2,3, 8, 6, 2, 2, 0.09310, 0.00000,-0.01075, 0.00000, 0.00000, 0.00000,"duuH3608"},
	{2,0,0,2,4, 9, 1, 1, 4,-0.03725,-0.00231, 0.00000,-0.00236,-0.00161, 0.00000,"duuH4109"},
	{2,0,0,2,4, 9, 1, 2, 2,-0.01650, 0.01354, 0.00447, 0.00000, 0.00000, 0.00000,"duuH4109"},
	{2,0,0,2,4, 9, 2, 1, 3,-0.01119,-0.00635, 0.00000,-0.00300, 0.00000, 0.00000,"duuH4209"},
	{2,0,0,2,4, 9, 2, 2, 2, 0.01270, 0.01550, 0.00405, 0.00000, 0.00000, 0.00000,"duuH4209"},
	{2,0,0,2,4, 9, 3, 1, 0, 0.02391, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4309"},
	{2,0,0,2,4, 9, 3, 2, 2, 0.04097, 0.01368, 0.00263, 0.00000, 0.00000, 0.00000,"duuH4309"},
	{2,0,0,2,4, 9, 4, 2, 0, 0.08101, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4409"},
	{2,0,0,2,4, 9, 6, 2, 0, 0.15338, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH4609"},
	{2,0,0,2,3,10, 1, 1, 3,-0.03515,-0.01452,-0.00927,-0.00336, 0.00000, 0.00000,"duuH3110"},
	{2,0,0,2,3,10, 1, 2, 3,-0.03710, 0.00900, 0.01158, 0.00367, 0.00000, 0.00000,"duuH3110"},
	{2,0,0,2,3,10, 2, 1, 3,-0.03236,-0.00973,-0.01065,-0.00401, 0.00000, 0.00000,"duuH3210"},
	{2,0,0,2,3,10, 2, 2, 2,-0.02718, 0.00000, 0.01247, 0.00000, 0.00000, 0.00000,"duuH3210"},
	{2,0,0,2,3,10, 3, 1, 2,-0.02820, 0.00000,-0.01034, 0.00000, 0.00000, 0.00000,"duuH3310"},
	{2,0,0,2,3,10, 3, 2, 3,-0.01776, 0.00000, 0.01068, 0.00519, 0.00000, 0.00000,"duuH3310"},
	{2,0,0,2,3,10, 4, 1, 3, 0.01597,-0.08290, 0.05043,-0.02161, 0.00000, 0.00000,"duuH3410"},
	{2,0,0,2,3,10, 4, 2, 3,-0.04278, 0.07563,-0.05006, 0.02230, 0.00000, 0.00000,"duuH3410"},
	{2,0,0,2,3,10, 5, 1, 3, 0.00924,-0.07394, 0.04861,-0.01978, 0.00000, 0.00000,"duuH3510"},
	{2,0,0,2,3,10, 5, 2, 3,-0.04294, 0.08095,-0.04671, 0.02037, 0.00000, 0.00000,"duuH3510"},
	{2,0,0,2,3,10, 6, 1, 3, 0.01940,-0.07628, 0.05063,-0.02008, 0.00000, 0.00000,"duuH3610"},
	{2,0,0,2,3,10, 6, 2, 3,-0.02696, 0.07764,-0.05352, 0.02337, 0.00000, 0.00000,"duuH3610"},
	{2,0,0,2,3,12, 1, 1, 2, 0.03257, 0.00000,-0.00501, 0.00000, 0.00000, 0.00000,"duuH3112"},
	{2,0,0,2,3,12, 1, 2, 2, 0.04224, 0.00395, 0.00190, 0.00000, 0.00000, 0.00000,"duuH3112"},
	{2,0,0,2,3,12, 2, 1, 2, 0.03263, 0.00000,-0.00577, 0.00000, 0.00000, 0.00000,"duuH3212"},
	{2,0,0,2,3,12, 2, 2, 2, 0.04276, 0.00000, 0.00205, 0.00000, 0.00000, 0.00000,"duuH3212"},
	{2,0,0,2,3,12, 3, 1, 2, 0.03423, 0.00000,-0.00584, 0.00000, 0.00000, 0.00000,"duuH3312"},
	{2,0,0,2,3,12, 3, 2, 4, 0.03699,-0.00273, 0.00000, 0.00197, 0.00127, 0.00000,"duuH3312"},
	{2,0,0,3,6, 1, 1, 1, 4,-0.05070, 0.00000, 0.00000, 0.00000, 0.00306, 0.00000,"duuH6101"},
	{2,0,0,3,6, 1, 1, 2, 0,-0.02217, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6101"},
	{2,0,0,3,6, 1, 2, 1, 0,-0.02460, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6201"},
	{2,0,0,3,6, 1, 2, 2, 0,-0.04439, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6201"},
	{2,0,0,3,6, 1, 3, 1, 0, 0.07163, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6301"},
	{2,0,0,3,6, 1, 4, 1, 1, 0.10916, 0.00666, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6401"},
	{2,0,0,3,6, 1, 4, 2, 5,-0.01191, 0.00000, 0.00000, 0.00000, 0.00000, 0.01421,"duuH6401"},
	{2,0,0,3,6, 1, 5, 1, 2, 0.07829, 0.00000,-0.00782, 0.00000, 0.00000, 0.00000,"duuH6501"},
	{2,0,0,3,6, 1, 6, 1, 2, 0.11365, 0.00000,-0.00743, 0.00000, 0.00000, 0.00000,"duuH6601"},
	{2,0,0,3,6, 1, 6, 2, 2, 0.09276,-0.01158, 0.00496, 0.00000, 0.00000, 0.00000,"duuH6601"},
	{2,0,0,3,6, 1, 7, 1, 0, 0.14567, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6701"},
	{2,0,0,3,6, 1, 7, 2, 3, 0.13979,-0.00653, 0.00000, 0.00270, 0.00000, 0.00000,"duuH6701"},
	{2,0,0,3,5, 2, 1, 1, 4, 0.01706, 0.00000,-0.04979,-0.00876, 0.00670, 0.00000,"duuH5102"},
	{2,0,0,3,5, 2, 1, 2, 3,-0.08083, 0.00000, 0.05158, 0.00691, 0.00000, 0.00000,"duuH5102"},
	{2,0,0,3,5, 2, 2, 1, 2, 0.03414, 0.00000,-0.04379, 0.00000, 0.00000, 0.00000,"duuH5202"},
	{2,0,0,3,5, 2, 2, 2, 2,-0.10838, 0.00000, 0.04242, 0.00000, 0.00000, 0.00000,"duuH5202"},
	{2,0,0,3,5, 2, 3, 1, 3, 0.02111, 0.00000,-0.05151,-0.01148, 0.00000, 0.00000,"duuH5302"},
	{2,0,0,3,5, 2, 3, 2, 3,-0.07490, 0.00000, 0.05327, 0.00874, 0.00000, 0.00000,"duuH5302"},
	{2,0,0,3,5, 2, 4, 1, 4, 0.02154, 0.00000,-0.05281,-0.01057, 0.00605, 0.00000,"duuH5402"},
	{2,0,0,3,5, 2, 4, 2, 3,-0.06619, 0.00000, 0.05326, 0.01070, 0.00000, 0.00000,"duuH5402"},
	{2,0,0,3,5, 2, 5, 1, 4, 0.02497, 0.00000, 0.00000,-0.02079,-0.02721, 0.00000,"duuH5502"},
	{2,0,0,3,5, 2, 5, 2, 5,-0.11045, 0.00496, 0.00000, 0.02798, 0.00000, 0.01517,"duuH5502"},
	{2,0,0,3,5, 2, 6, 1, 5, 0.00666, 0.01998,-0.01558,-0.01704, 0.00000,-0.01111,"duuH5602"},
	{2,0,0,3,5, 2, 6, 2, 5,-0.10872, 0.00000, 0.00000, 0.03208, 0.00000, 0.01488,"duuH5602"},
	{2,0,0,3,5, 2, 7, 1, 5, 0.03278, 0.00000, 0.00000,-0.03115, 0.00000,-0.01530,"duuH5702"},
	{2,0,0,3,5, 2, 7, 2, 4,-0.10190, 0.00000, 0.04642, 0.02269, 0.02668, 0.00000,"duuH5702"},
	{2,0,0,3,6, 3, 1, 1, 4,-0.01450, 0.00000,-0.01452,-0.00917,-0.00411, 0.00000,"duuH6103"},
	{2,0,0,3,6, 3, 1, 2, 3,-0.04244,-0.00936, 0.01029, 0.00551, 0.00000, 0.00000,"duuH6103"},
	{2,0,0,3,6, 3, 2, 1, 4,-0.00080, 0.00650,-0.01093,-0.00628,-0.00430, 0.00000,"duuH6203"},
	{2,0,0,3,6, 3, 2, 2, 4,-0.00700,-0.01047, 0.01204, 0.00570, 0.00335, 0.00000,"duuH6203"},
	{2,0,0,3,6, 3, 3, 1, 4, 0.02679, 0.00287,-0.00886,-0.00550,-0.00428, 0.00000,"duuH6303"},
	{2,0,0,3,6, 3, 3, 2, 4,-0.00242,-0.00697, 0.01173, 0.00536, 0.00274, 0.00000,"duuH6303"},
	{2,0,0,3,6, 3, 4, 1, 4, 0.03383, 0.00000,-0.02131, 0.00000,-0.01225, 0.00000,"duuH6403"},
	{2,0,0,3,6, 3, 4, 2, 3,-0.04394, 0.00000, 0.01550, 0.01067, 0.00000, 0.00000,"duuH6403"},
	{2,0,0,3,6, 3, 5, 1, 5, 0.06318, 0.00000, 0.00000,-0.00952, 0.00240,-0.00528,"duuH6503"},
	{2,0,0,3,6, 3, 5, 2, 5, 0.01483, 0.00000, 0.01336, 0.00959, 0.00356, 0.00231,"duuH6503"},
	{2,0,0,3,6, 3, 6, 1, 4, 0.08205, 0.00000,-0.01002,-0.00444,-0.00434, 0.00000,"duuH6603"},
	{2,0,0,3,6, 3, 6, 2, 4, 0.04427,-0.00471, 0.01236, 0.00819, 0.00287, 0.00000,"duuH6603"},
	{2,0,0,3,6, 3, 7, 1, 3, 0.24832, 0.00000,-0.19212,-0.06772, 0.00000, 0.00000,"duuH6703"},
	{2,0,0,3,6, 3, 7, 2, 3, 0.00708, 0.00000, 0.01591, 0.01021, 0.00000, 0.00000,"duuH6703"},
	{2,0,0,3,5, 4, 1, 1, 0,-0.00806, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5104"},
	{2,0,0,3,5, 4, 1, 2, 3, 0.00414, 0.00485, 0.00000, 0.00346, 0.00000, 0.00000,"duuH5104"},
	{2,0,0,3,5, 4, 2, 1, 2,-0.02416,-0.00534, 0.00175, 0.00000, 0.00000, 0.00000,"duuH5204"},
	{2,0,0,3,5, 4, 2, 2, 3,-0.01244, 0.00972, 0.00000, 0.00422, 0.00000, 0.00000,"duuH5204"},
	{2,0,0,3,5, 4, 3, 1, 3,-0.03558,-0.00349, 0.00000,-0.00196, 0.00000, 0.00000,"duuH5304"},
	{2,0,0,3,5, 4, 3, 2, 0,-0.04647, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5304"},
	{2,0,0,3,5, 4, 4, 1, 2,-0.06015,-0.00478, 0.00192, 0.00000, 0.00000, 0.00000,"duuH5404"},
	{2,0,0,3,5, 4, 4, 2, 1,-0.04692, 0.00749, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5404"},
	{2,0,0,3,5, 4, 5, 1, 1,-0.08091,-0.01084, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5504"},
	{2,0,0,3,5, 4, 5, 2, 1,-0.05311, 0.01105, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5504"},
	{2,0,0,3,5, 4, 6, 1, 2,-0.09404,-0.01126, 0.00192, 0.00000, 0.00000, 0.00000,"duuH5604"},
	{2,0,0,3,5, 4, 6, 2, 1,-0.06846, 0.01255, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5604"},
	{2,0,0,3,5, 4, 7, 1, 4,-0.10573,-0.01090, 0.00000, 0.00000, 0.00202, 0.00000,"duuH5704"},
	{2,0,0,3,5, 4, 7, 2, 3,-0.08339, 0.01382, 0.00000, 0.00504, 0.00000, 0.00000,"duuH5704"},
	{2,0,0,3,6, 5, 1, 1, 5,-0.05288, 0.00000, 0.00000,-0.00728, 0.00000,-0.00476,"duuH6105"},
	{2,0,0,3,6, 5, 1, 2, 4,-0.06478, 0.00000, 0.03231, 0.00000, 0.02050, 0.00000,"duuH6105"},
	{2,0,0,3,6, 5, 2, 1, 5,-0.04793, 0.00000, 0.00000,-0.00959, 0.00000,-0.00611,"duuH6205"},
	{2,0,0,3,6, 5, 3, 1, 3,-0.02874, 0.00000, 0.00000,-0.00664, 0.00000, 0.00000,"duuH6305"},
	{2,0,0,3,6, 5, 4, 1, 2, 0.02300, 0.00000,-0.00979, 0.00000, 0.00000, 0.00000,"duuH6405"},
	{2,0,0,3,6, 5, 4, 2, 0,-0.10098, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6405"},
	{2,0,0,3,6, 5, 5, 1, 3,-0.05424, 0.00000, 0.00000,-0.00377, 0.00000, 0.00000,"duuH6505"},
	{2,0,0,3,6, 5, 5, 2, 1,-0.03557, 0.00560, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6505"},
	{2,0,0,3,6, 5, 6, 1, 3,-0.05128, 0.00000, 0.00000,-0.00258, 0.00000, 0.00000,"duuH6605"},
	{2,0,0,3,6, 5, 6, 2, 2,-0.03258, 0.00785, 0.00526, 0.00000, 0.00000, 0.00000,"duuH6605"},
	{2,0,0,3,6, 5, 7, 1, 3,-0.05461, 0.00000, 0.00000,-0.00343, 0.00000, 0.00000,"duuH6705"},
	{2,0,0,3,6, 5, 7, 2, 2,-0.03575, 0.00452, 0.00553, 0.00000, 0.00000, 0.00000,"duuH6705"},
	{2,0,0,3,5, 6, 1, 1, 0,-0.02310, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5106"},
	{2,0,0,3,5, 6, 1, 2, 0,-0.02993, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5106"},
	{2,0,0,3,5, 6, 2, 1, 2,-0.02896, 0.00000, 0.00214, 0.00000, 0.00000, 0.00000,"duuH5206"},
	{2,0,0,3,5, 6, 2, 2, 0,-0.03131, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5206"},
	{2,0,0,3,5, 6, 3, 1, 2,-0.04245,-0.00754, 0.00219, 0.00000, 0.00000, 0.00000,"duuH5306"},
	{2,0,0,3,5, 6, 3, 2, 0,-0.04087, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5306"},
	{2,0,0,3,5, 6, 4, 1, 2,-0.05202,-0.00663, 0.00314, 0.00000, 0.00000, 0.00000,"duuH5406"},
	{2,0,0,3,5, 6, 4, 2, 1,-0.04193, 0.00450, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5406"},
	{2,0,0,3,5, 6, 5, 1, 2,-0.06984,-0.00695, 0.00640, 0.00000, 0.00000, 0.00000,"duuH5506"},
	{2,0,0,3,5, 6, 5, 2, 0,-0.04064, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5506"},
	{2,0,0,3,5, 6, 6, 2, 5,-0.04665, 0.00442, 0.00000, 0.00000, 0.00000, 0.00254,"duuH5606"},
	{2,0,0,3,5, 6, 7, 1, 2,-0.07992,-0.01153, 0.00743, 0.00000, 0.00000, 0.00000,"duuH5706"},
	{2,0,0,3,5, 6, 7, 2, 5,-0.05010, 0.00775, 0.00000, 0.00000, 0.00000, 0.00234,"duuH5706"},
	{2,0,0,3,6, 7, 1, 2, 3,-0.09322, 0.01202, 0.00000, 0.00379, 0.00000, 0.00000,"duuH6107"},
	{2,0,0,3,6, 7, 2, 1, 1,-0.11962,-0.00322, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6207"},
	{2,0,0,3,6, 7, 2, 2, 0,-0.08227, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6207"},
	{2,0,0,3,6, 7, 3, 2, 1,-0.09165, 0.01130, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6307"},
	{2,0,0,3,5, 8, 1, 1, 3, 0.14700, 0.02140,-0.02100,-0.01391, 0.00000, 0.00000,"duuH5108"},
	{2,0,0,3,5, 8, 1, 2, 4,-0.04438, 0.00000, 0.04627, 0.02709, 0.01536, 0.00000,"duuH5108"},
	{2,0,0,3,5, 8, 2, 1, 1, 0.11009, 0.04693, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5208"},
	{2,0,0,3,5, 8, 2, 2, 3,-0.09920, 0.00000, 0.07749, 0.03787, 0.00000, 0.00000,"duuH5208"},
	{2,0,0,3,5, 8, 3, 1, 3, 0.09186, 0.01909,-0.02132,-0.01483, 0.00000, 0.00000,"duuH5308"},
	{2,0,0,3,5, 8, 3, 2, 4,-0.03205, 0.00000, 0.04654, 0.01946, 0.01503, 0.00000,"duuH5308"},
	{2,0,0,3,5, 8, 4, 1, 3, 0.08514, 0.02595, 0.00000,-0.01834, 0.00000, 0.00000,"duuH5408"},
	{2,0,0,3,5, 8, 4, 2, 4,-0.03790, 0.00000, 0.05649, 0.02693, 0.01416, 0.00000,"duuH5408"},
	{2,0,0,3,5, 8, 5, 1, 1, 0.05708,-0.00690, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5508"},
	{2,0,0,3,5, 8, 5, 2, 2, 0.07120, 0.00948, 0.00741, 0.00000, 0.00000, 0.00000,"duuH5508"},
	{2,0,0,3,5, 8, 6, 1, 3, 0.05381,-0.00999, 0.00000,-0.00428, 0.00000, 0.00000,"duuH5608"},
	{2,0,0,3,5, 8, 6, 2, 2, 0.07445, 0.00870, 0.00556, 0.00000, 0.00000, 0.00000,"duuH5608"},
	{2,0,0,3,5, 8, 7, 1, 3, 0.05519,-0.01292, 0.00000,-0.00529, 0.00000, 0.00000,"duuH5708"},
	{2,0,0,3,5, 8, 7, 2, 2, 0.07347, 0.00000, 0.01314, 0.00000, 0.00000, 0.00000,"duuH5708"},
	{2,0,0,3,6, 9, 1, 1, 2,-0.04468,-0.00968,-0.01049, 0.00000, 0.00000, 0.00000,"duuH6109"},
	{2,0,0,3,6, 9, 1, 2, 2,-0.04959, 0.00000, 0.03745, 0.00000, 0.00000, 0.00000,"duuH6109"},
	{2,0,0,3,6, 9, 2, 1, 5,-0.04119,-0.01382,-0.01107, 0.00000, 0.00000, 0.00275,"duuH6209"},
	{2,0,0,3,6, 9, 2, 2, 2,-0.05343, 0.01669, 0.01212, 0.00000, 0.00000, 0.00000,"duuH6209"},
	{2,0,0,3,6, 9, 3, 1, 5,-0.02111,-0.02049,-0.01111, 0.00000, 0.00000, 0.00309,"duuH6309"},
	{2,0,0,3,6, 9, 3, 2, 2,-0.05568, 0.02256, 0.01774, 0.00000, 0.00000, 0.00000,"duuH6309"},
	{2,0,0,3,6, 9, 4, 1, 0,-0.05207, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6409"},
	{2,0,0,3,6, 9, 4, 2, 1,-0.00476, 0.00884, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6409"},
	{2,0,0,3,6, 9, 5, 1, 0,-0.04466, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6509"},
	{2,0,0,3,6, 9, 6, 1, 0,-0.03769, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6609"},
	{2,0,0,3,6, 9, 6, 2, 0, 0.02473, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6609"},
	{2,0,0,3,6, 9, 7, 1, 0,-0.02699, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6709"},
	{2,0,0,3,5,10, 1, 1, 1,-0.08931,-0.01207, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5110"},
	{2,0,0,3,5,10, 1, 2, 2,-0.06041, 0.01541, 0.00514, 0.00000, 0.00000, 0.00000,"duuH5110"},
	{2,0,0,3,5,10, 2, 1, 4,-0.07809,-0.00932, 0.00000, 0.00263, 0.00144, 0.00000,"duuH5210"},
	{2,0,0,3,5,10, 2, 2, 2,-0.04683, 0.01776, 0.00607, 0.00000, 0.00000, 0.00000,"duuH5210"},
	{2,0,0,3,5,10, 3, 1, 2,-0.06356,-0.00794,-0.00596, 0.00000, 0.00000, 0.00000,"duuH5310"},
	{2,0,0,3,5,10, 3, 2, 1,-0.04040, 0.01562, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5310"},
	{2,0,0,3,5,10, 4, 1, 1,-0.05891,-0.00976, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5410"},
	{2,0,0,3,5,10, 4, 2, 3,-0.02739, 0.01765, 0.00578, 0.00424, 0.00000, 0.00000,"duuH5410"},
	{2,0,0,3,5,10, 5, 1, 1,-0.04901,-0.01239, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5510"},
	{2,0,0,3,5,10, 5, 2, 3,-0.01923, 0.01856, 0.00437, 0.00416, 0.00000, 0.00000,"duuH5510"},
	{2,0,0,3,5,10, 6, 1, 2,-0.04221,-0.01617, 0.00192, 0.00000, 0.00000, 0.00000,"duuH5610"},
	{2,0,0,3,5,10, 6, 2, 3,-0.02457, 0.00000, 0.00000, 0.00278, 0.00000, 0.00000,"duuH5610"},
	{2,0,0,3,5,10, 7, 1, 1,-0.03458,-0.01529, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5710"},
	{2,0,0,3,5,10, 7, 2, 2,-0.00421, 0.01826, 0.00487, 0.00000, 0.00000, 0.00000,"duuH5710"},
	{2,0,0,3,6,11, 1, 2, 4, 0.07484, 0.01706, 0.00336, 0.00000,-0.00203, 0.00000,"duuH6111"},
	{2,0,0,3,6,11, 2, 1, 2, 0.04744,-0.01235,-0.00576, 0.00000, 0.00000, 0.00000,"duuH6211"},
	{2,0,0,3,6,11, 2, 2, 4, 0.07198, 0.01846, 0.00234, 0.00000,-0.00227, 0.00000,"duuH6211"},
	{2,0,0,3,6,11, 3, 1, 3, 0.04279,-0.01701,-0.00666,-0.00512, 0.00000, 0.00000,"duuH6311"},
	{2,0,0,3,6,11, 3, 2, 4, 0.07034, 0.01672, 0.00331,-0.00343,-0.00227, 0.00000,"duuH6311"},
	{2,0,0,3,5,12, 1, 1, 2,-0.03864, 0.00000, 0.00555, 0.00000, 0.00000, 0.00000,"duuH5112"},
	{2,0,0,3,5,12, 1, 2, 1, 0.02564, 0.00647, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5112"},
	{2,0,0,3,5,12, 2, 1, 5,-0.02105, 0.00000, 0.00000, 0.00000,-0.00317,-0.00180,"duuH5212"},
	{2,0,0,3,5,12, 2, 2, 1, 0.04408, 0.00622, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5212"},
	{2,0,0,3,5,12, 3, 1, 1,-0.00237,-0.00639, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5312"},
	{2,0,0,3,5,12, 3, 2, 1, 0.06498, 0.00548, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5312"},
	{2,0,0,3,5,12, 4, 1, 1, 0.03481,-0.02510, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5412"},
	{2,0,0,3,5,12, 4, 2, 5, 0.08776, 0.00000, 0.00000, 0.00000, 0.00000,-0.00199,"duuH5412"},
	{2,0,0,3,5,12, 5, 1, 0, 0.04836, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5512"},
	{2,0,0,3,5,12, 5, 2, 1, 0.08249, 0.00808, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5512"},
	{2,0,0,3,5,12, 6, 1, 0, 0.08502, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5612"},
	{2,0,0,3,5,12, 6, 2, 2, 0.10491, 0.00834, 0.00599, 0.00000, 0.00000, 0.00000,"duuH5612"},
	{2,0,0,3,5,12, 7, 1, 3, 0.09606,-0.00081, 0.00000,-0.01025, 0.00000, 0.00000,"duuH5712"},
	{2,0,0,3,5,12, 7, 2, 1, 0.11745, 0.00902, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5712"},
	{2,0,0,3,6,13, 1, 1, 1,-0.05648,-0.01481, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6113"},
	{2,0,0,3,6,13, 1, 2, 5,-0.01846, 0.02036, 0.00000, 0.00000, 0.00000, 0.00147,"duuH6113"},
	{2,0,0,3,6,13, 2, 1, 1,-0.05195,-0.00969, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6213"},
	{2,0,0,3,6,13, 2, 2, 5,-0.01170, 0.02119, 0.00000, 0.00000, 0.00000, 0.00094,"duuH6213"},
	{2,0,0,3,6,13, 3, 1, 4,-0.04212,-0.01088, 0.00000, 0.00000, 0.00127, 0.00000,"duuH6313"},
	{2,0,0,3,6,13, 3, 2, 5,-0.00542, 0.02025, 0.00000, 0.00000, 0.00000, 0.00137,"duuH6313"},
	{2,0,0,3,6,13, 4, 1, 1,-0.02926,-0.00967, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6413"},
	{2,0,0,3,6,13, 4, 2, 5,-0.00226, 0.01788, 0.00000, 0.00000, 0.00126, 0.00151,"duuH6413"},
	{2,0,0,3,6,13, 5, 1, 3,-0.02141,-0.00774,-0.00291,-0.00271, 0.00000, 0.00000,"duuH6513"},
	{2,0,0,3,6,13, 6, 1, 2,-0.01447,-0.01139,-0.00143, 0.00000, 0.00000, 0.00000,"duuH6613"},
	{2,0,0,3,6,13, 7, 1, 1,-0.00052,-0.00383, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6713"},
	{2,0,0,3,6,13, 7, 2, 5, 0.01746, 0.01361, 0.00000, 0.00000, 0.00000, 0.00136,"duuH6713"},
	{2,0,0,3,5,14, 1, 1, 5,-0.10686, 0.00000, 0.00000, 0.00000, 0.00000, 0.00395,"duuH5114"},
	{2,0,0,3,5,14, 1, 2, 0,-0.10790, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5114"},
	{2,0,0,3,5,14, 2, 1, 4,-0.08936,-0.00811, 0.00000, 0.00000, 0.00213, 0.00000,"duuH5214"},
	{2,0,0,3,5,14, 2, 2, 1,-0.03992, 0.00607, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5214"},
	{2,0,0,3,5,14, 3, 1, 1,-0.06861,-0.00700, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5314"},
	{2,0,0,3,5,14, 3, 2, 4, 0.00200, 0.00000, 0.00000, 0.00000, 0.04775, 0.00000,"duuH5314"},
	{2,0,0,3,5,14, 4, 1, 1,-0.05568,-0.00576, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5414"},
	{2,0,0,3,5,14, 4, 2, 4,-0.00191, 0.00000, 0.00678, 0.00000, 0.01738, 0.00000,"duuH5414"},
	{2,0,0,3,5,14, 5, 1, 1, 0.00390,-0.02469, 0.00000, 0.00000, 0.00000, 0.00000,"duuH5514"},
	{2,0,0,3,5,14, 5, 2, 2, 0.00535, 0.00000, 0.03057, 0.00000, 0.00000, 0.00000,"duuH5514"},
	{2,0,0,3,5,14, 6, 1, 3, 0.01744,-0.02445,-0.00345,-0.00253, 0.00000, 0.00000,"duuH5614"},
	{2,0,0,3,5,14, 6, 2, 3, 0.04405, 0.00000, 0.00000,-0.00331, 0.00000, 0.00000,"duuH5614"},
	{2,0,0,3,5,14, 7, 1, 4, 0.01768,-0.01934, 0.00000, 0.00000, 0.00114, 0.00000,"duuH5714"},
	{2,0,0,3,5,14, 7, 2, 5, 0.06860, 0.00000, 0.00000,-0.00419, 0.00000,-0.00265,"duuH5714"},
	{2,0,0,3,6,15, 5, 1, 3,-0.09543,-0.00648,-0.00350,-0.00353, 0.00000, 0.00000,"duuH6515"},
	{2,0,0,3,6,15, 5, 2, 3,-0.07877, 0.00724, 0.00433, 0.00365, 0.00000, 0.00000,"duuH6515"},
	{2,0,0,3,6,15, 6, 1, 3,-0.09611,-0.00576,-0.00469,-0.00350, 0.00000, 0.00000,"duuH6615"},
	{2,0,0,3,6,15, 6, 2, 3,-0.06652, 0.01926, 0.00000, 0.00343, 0.00000, 0.00000,"duuH6615"},
	{2,0,0,3,6,15, 7, 1, 5,-0.09433, 0.00000,-0.00509, 0.00000, 0.00000, 0.00236,"duuH6715"},
	{2,0,0,3,6,15, 7, 2, 1,-0.07992, 0.00756, 0.00000, 0.00000, 0.00000, 0.00000,"duuH6715"},
	{2,0,0,3,5,16, 5, 1, 3,-0.05853,-0.02450,-0.01613,-0.01162, 0.00000, 0.00000,"duuH5516"},
	{2,0,0,3,5,16, 5, 2, 3,-0.15949, 0.03118, 0.02200, 0.01082, 0.00000, 0.00000,"duuH5516"},
	{2,0,0,3,5,16, 6, 1, 3,-0.06440, 0.00000,-0.02142,-0.00883, 0.00000, 0.00000,"duuH5616"},
	{2,0,0,3,5,16, 6, 2, 3,-0.13909, 0.00106, 0.03210, 0.01566, 0.00000, 0.00000,"duuH5616"},
	{2,0,0,3,5,16, 7, 1, 4,-0.05273, 0.00000,-0.02293,-0.00761,-0.00329, 0.00000,"duuH5716"},
	{2,0,0,3,5,16, 7, 2, 3,-0.07410, 0.00060, 0.02157, 0.00684, 0.00000, 0.00000,"duuH5716"}
};
