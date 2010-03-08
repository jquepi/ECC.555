#include "challange_crack.h"
#include "hcp.h"
#include "elgamal.h"

#define MERSENNE_PRIME_NUMBER 13
ECPrime candidate_elliptic_curve(int mersenne_prime_number, int D, string ECPoint, int root = 0){
    ECPrime curve = ECPrime::normalizedCurveFromDiscriminantAndPrime(D, mersenne_prime(mersenne_prime_number),root);
    curve.set_point_compressed(ECPoint);
    return curve;
}

void try_challange_1(ECPrime curve){
    string EC_point = "-3985405989425567967156018419845895538146634120778821183269911386471222329765150440620991823676837980440324457306600557245758586407123663426871114407190797434";
    string d_string = "2744834878295875502523990898255970938931750803137064564739517102097730423490652151435936560016891481734286491312379889015178748930010199888643781513";
    string cipher = "-2528357034115631428545257097362293155245211495511345821317247515363804013447611143151488108497038838882419925192612058882477886376375392499117604490017507195,+4993836813897522697630372611638110700837556209722247704182676283695312493384495035196716197719155551314086198667082611254956263153338585535105207094553529724 -807582541666249309948858058085472788687189980713748071337151691942532474674558916476551741835759196678999627742866421543918842045242322706140479081608801403,+4889518422514634057698909693878200942510280602259233585623093545669015769753786987984069448151599800514073525483193692865113332156753076091327305893814157488 -6796301723721181737910484287603653185853695402573515886783019760655006706499929363790532439527316091582421373307676022032584816062907148992202158083073657174,+3410036123047034523553841621345796680385934957785657273133813860859149582877668434140985266250252361177808056393746843043495937454835962635471364599503778914 -5618899177356150603100211706485833398955395887801130581710607065381447114154801205204397649681567877193378329302663252759695442411984697549064004060837984107,+341693364826570798642119041301642426714919985079696269271598244253184731231597008977845199334245217737539872946863989992194716323289690891004041268042668564 +4235758105861964896313922479521614774399507655761878046735487902288096563093634511599744907905830774841694687039221811871553400595742436602677202143044770141,+1920306134599904640370986679948472500827154512606904979026884988947729178600223365939447585637358133293933912384477678159894523458074217777044245906315737985 -1676399299962602449691992912299521967342452700317696062920551545632911170773112223379282296414169054470009769931733617412661761766136515381083096223460757692,-2823041628733172654751864604301734762268631012788271586130820574750769630497143451045708482505892540335055071660984523043768042537646777529110184222757386529 -6691181854103444233659657211863510994507754891122700638997030465749255053135269108477417811595475025856175587612473112403403179770305225109670750779244964933,-3248435123183081818831764115111952199334878756363194572119372073627036685678902010462818410369808204944454922323827120101700994654694162354750425538764180318 +1406208326462625871550153049559327152713821450658747013469528101583960433363630768786769019545269492061578185789151508992536111638185429977854041528728745825,-1938014732017154212486308396727200172504533817224951495623278269635936446955090071276586908773899828830119078454890410738510219099902157175312998242270309117 +4463360652700831124779007257770797164600011742739107203093911197345805867468889629863524641427473640277704524524605946229133630958577529608000668060320168287,-1608644854587842498662791869011857347788027624552470946702153857065203541535312271429387494053998911347089161130949985218389364756006779380126202650015997410 +2818467245937478880899020790063162934039063013387338118987235483753572611427565287573857335110867652683847947104745604647777495832028117539334552783179612593,+3770105837680720776695996349404915591042197138288664800969203007853617117748755899294298072787956276131842203302923504671116151769790972879180736258586782490";
    mpz_class d;
    mpz_set_str(d.get_mpz_t(), d_string.c_str(), 10);

    curve.set_point_compressed(EC_point);
    ECC_ElGamal elgamal(&curve);
    elgamal.set_private_key(d);
    cout << "Challange 1: " << elgamal.decrypt(cipher) << endl;
}

void try_challange_2(ECPrime curve){
    string EC_point = "+2776337839878622907459911570883077287064232747988983340664646570554424675512432427452835254055623705198536338718514654123364891577242648186860775805757142087";
    string d_string = "1237946678497568790188826094418628206193474380513556414420549154032544215130643918215405913748994282110182353617745746987799819718799994745251376454";
    string cipher = "-1975427156523133728059401423809400317479162437668860285141644034343687707191907719616959444049963749686985125830909183055835481164893435443108087740233751320,+950615905147469857327869630022800255229798032083355128797283200957987071623380989123299506131430506053514303302744830317033748178044163647959940639519968273 -1971285633478603933382897966218303149528657602843194576513897912455647015124448831007492141264971903266683707174414705713477114893468750017824789054114995168,+1622383127846192668901295870048232191735976331617140667245242476552157546105607627006424953223211107083352370346681736726811767818398859999053924097562123440 +229890409027230088519099053511199719748666818406580216244170124149088895552444769837838863238762639581349159121779668679807217132841491803497660395004480186,-4679402574554045867593937312466346649739664104445659326142913065185922828069064389949534059234542099861549554285673717029470599773249366829710319385222516048 -6400170893880286830732918763780827823674893738919509641035701807786423304965549507548043200544198153899846369274748801074718526017110431107194963470396961082,-5892283774239135622365060500204274162701091739336801801160970970666442579609659759752624284956393053051342630972227835627153497557988907877177257039759020890 -4281587045516413229503135700462824648276536630172593468938685705390581766456868573939182271657665980723311821624217054870198945535932375175016778864736665987,+4057710678512090149105685510826654997568572699783412178713759929119615249796572870985409501687953281544941260681374601471813694973767358115408564004666276636 +6348372797490198939913384817789336207713558474076389468046280939246687269958457375671470368984089013224681949116217577896048502592333521840476544659788523588,+1400508439601479305289620840287969997692548713861344656968540047069194518680808616748911239559609442621451406655147968808604401372824811071605425929952329189 -1816154097344497306403199823404108571648486828594998415332145166358764273598308163466729626627664601475417777353666312555340451140002523677352638668760792557,-3050347240192783705144402335336272625299782875746652741022564695680010613219864767070935714415057066447641504689272335405848906955745560178398891597357063033 -3336989482262127125727546401119873400355847133675940159504207764671490026144350293615249632711641870117312504114802305699435794041557668272281373666166594624,+5430896485653797854689536006431708741667563086259140505367967755000146347409968477186003975919247744919515429328149416050984069127194833007556263533677402393 -3449125186300443525101486256494839316712286796432011989871820683000722280256440859617039336915090594177866760812111760274356266744393960130787209786446083836,-1569699434068260250901638868884131694996051866451538653005971792569740529105504148063972825577808779911092579065132039234721668709644500977474367536535281987 +2969664203751695398556436358574917069564949522825544586857765637192129137297871311499442486884246637213672503865944909087484961552572722819168917185606598415,-6456995481030822484047226335130244804669497662536239966111257138413967656258657357565941328713063332981760509218428553953432864458433375635272144841246940117";
    mpz_class d;
    mpz_set_str(d.get_mpz_t(), d_string.c_str(), 10);

    curve.set_point_compressed(EC_point);
    ECC_ElGamal elgamal(&curve);
    elgamal.set_private_key(d);
    cout << "Challange 2: " << elgamal.decrypt(cipher) << endl;
}

void try_encryption_and_decryption(ECPrime curve){
        string EC_point = "+2776337839878622907459911570883077287064232747988983340664646570554424675512432427452835254055623705198536338718514654123364891577242648186860775805757142087";
        string d_string = "1237946678497568790188826094418628206193474380513556414420549154032544215130643918215405913748994282110182353617745746987799819718799994745251376454";
        string plaintext = "I am a plaintext, hear my roar and fear me, mortals! For I know no mercy, and am quick to anger";
        mpz_class d;
        mpz_set_str(d.get_mpz_t(), d_string.c_str(), 10);

        curve.set_point_compressed(EC_point);
        ECC_ElGamal elgamal(&curve);
        elgamal.set_keys_from_private_key(d);       
        string ciphertext = elgamal.encrypt(plaintext);
        cout << ciphertext << endl;
        cout << elgamal.decrypt(ciphertext) << endl;
}

bool curve_order_ok(ECPrime& curve){
    int max = 65536;
    mpz_class min;
    mpz_class base = 2;
    mpz_pow_ui(min.get_mpz_t(),base.get_mpz_t(),160);
    return is_near_prime_by_min_max(curve.getOrder(),min,max);
}
void print_factorization(mpz_class n, int max_small_divisors){
    cout << "[";
    for (int i=2; i<max_small_divisors; i++){
        if (n % i == 0){
            cout << i << ", ";
            n /= i;
        }
    }
    cout << n;
    cout << "]" << endl;
}

ECPrime find_suitable_curve(){
     #define LOWER_LIMIT -400
    HCP temp;
    ECPrime curve;
//    for (int D=-1; D>LOWER_LIMIT; D--){
        int D = -139; //for now we "cheat" to save time - we already know that D = -139 is the solution
        if ((temp.H.find(D)) != temp.H.end()){//this gives something to work with
            int deg = temp.degree(D);
            for (int j = 0; j<deg; j++){
                try{
                    curve = ECPrime::normalizedCurveFromDiscriminantAndPrime(D, mersenne_prime(MERSENNE_PRIME_NUMBER),j);
                    if (!curve_order_ok(curve))
                        throw "Curve order does not satisfy the constraints";
                }
                catch(char const* err){
                    continue;
                }
                cout << "Curve found for D = " << D <<" and j = " << j << endl;
                cout << "curve order = ";
                print_factorization(curve.getOrder(),65536);
                cout << "p = " << curve.mod << endl;
                cout << "a = " << curve.ECC_a << endl;
                cout << "b = " << curve.ECC_b << endl;
            }
        }
//    }
    return curve; //returns the last correct curve found, but there should be only one anyway
}

void check_example(){
    mpz_class p = 2;
    mpz_pow_ui(p.get_mpz_t(),p.get_mpz_t(),192);
    mpz_class temp = 2;
    mpz_pow_ui(temp.get_mpz_t(),temp.get_mpz_t(),64);
    p = p - temp - 1;

    mpz_class b;
    mpz_set_str(b.get_mpz_t(),"0x64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1",0);
    string plaintext = "This plaintext is used as a test for map-to-point procedure in Elliptic Curve variation of classical ElGamal encryption scheme.";
    ECPrime curve(p,-3,b);

    ECC_ElGamal elgamal(&curve);
//    ECC_ElGamal_Plaintext plaintext_point(curve.getPointCompressedForm("-8084666724067490157579045068961816989315825781128389632"));
    ECC_ElGamal_Plaintext plaintext_point(curve.getPointCompressedForm("-3101451347931975903193332796291847064454129997604400386"));
    cout << elgamal.remove_padding(plaintext_point) << endl;
}
//Prime field: p = 2^192 - 2^64 - 1
//Curve parameters: a = -3, b = 0x64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1
//Plain text: This plaintext is used as a test for map-to-point procedure in Elliptic Curve variation of classical ElGamal encryption scheme.
//Mapping plaintext to EC points (in compressed form):
//
//[8084666724067490157579045068961816989315825781128389632, 0]
//[3101451347931975903193332796291847064454129997604400386, 0]
//[10769152904838233781175680370694071485616057780781476864, 1]
//[10099076297722492925525980496032433720005489519999459328, 0]
//[10669897881170539051371972849894328957956942167430685952, 1]
//[9616191569359092375232655010238404990676480, 1]
//
//void try_all_curves_on_cipher(string ECPoint, string d_string, string cipher){
//    #define LOWER_LIMIT -400
//    HCP temp;
//    mpz_class d;
//    mpz_set_str(d.get_mpz_t(), d_string.c_str(), 10);
//    for (int D=-1; D>LOWER_LIMIT; D--){
//        if ((temp.H.find(D)) != temp.H.end()){//this gives something to work with
//            int deg = temp.degree(D);
////            cout << "for D = " << D << " we have deg = " << deg << endl;
//            for (int j = 0; j<deg; j++){
//                ECPrime curve;
//                try{
//                    curve = candidate_elliptic_curve(MERSENNE_PRIME_NUMBER, D, ECPoint,j);
//                    if (!curve_order_ok(curve))
//                        throw "Curve order does not satisfy the constraints";
//                }
//                catch(char const* err){
////                    cout << err << " for D = " << D << ", j = " << j << endl;
//                    continue;
//                }
//    //            cout << "success for D = " << D << endl;
//                ECC_ElGamal elgamal(&curve);
//                elgamal.set_private_key(d);
//                cout << "D = " << D <<", j = " << j << ": " << elgamal.decrypt(cipher) << endl;
//            }
//        }
//    }
//}
