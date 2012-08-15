// Project specific includes
#include <config.h>
#include <system/debug/dump_memory.hh>
#include <system/debug/location.hh>
#include <system/debug/out_any.hh>
#include <system/debug/type_name.hh>
#include <messages/irs.hh>
#include <common/constants.hh>

// Standard includes
// #define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/auto_unit_test.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct radar_param
{
    string name;
    int type_of_targets;
    int time_off_ready_cmmn ;
    int time_off_ready_accel ;
    int time_prepare_radtn ;
    int cont_work_time ;
    int frequency_band ;
    double path_efficiency ;
    double wave_length ;
    int ant_gain_factor ;
    double ant_side_lobe_level ;
    double lobe_side_orient ;
    double noise_ratio ;
    double blind_zone ;
    int targets_qty ;
    int scans_qty ;
    int operators_qty ;
    int targets_op_qty ;
    double bearing_rmse ;
    double range_rmse ;
    double elev_rmse ;
    double speed_rmse ;
    double course_rmse ;

    struct mode
    {
        int mode_no ;
        double range_max ;
        double rotation_speed ;
        double elevation_max ;
        int potential_flag ;
        double power_potential;
        double pulse_power ;
        int time_bandwidth ;
        double sensibility ;

        mode():
            mode_no(0)
          , range_max(0)
          , rotation_speed(0)
          , elevation_max(0)
          , potential_flag(0)
          , power_potential(0)
          , pulse_power(0)
          , time_bandwidth(0)
          , sensibility(0)
        {}

        friend ostream& operator<< (ostream&, const mode&);
        friend fstream& operator<< (fstream&, const mode&);
    };

    friend ostream& operator<< (ostream& , const radar_param&);
    friend fstream& operator<< (fstream& , const radar_param&);

    vector<mode> modes;
};

ostream& operator<< (ostream& os, const radar_param::mode& mod)
{
    os << "mode_no = " <<  mod.mode_no << endl;
    os << "range_max = " <<  mod.range_max << endl;
    os << "rotation_speed = " <<  mod.rotation_speed << endl;
    os << "elevation_max = " <<  mod.elevation_max << endl;
    os << "potential_flag = " <<  mod.potential_flag << endl;
    os << "power_potential = " <<  mod.power_potential << endl;
    os << "pulse_power = " <<  mod.pulse_power << endl;
    os << "time_bandwidth = " <<  mod.time_bandwidth << endl;
    os << "sensibility = " <<  mod.sensibility << endl;

    return os;
}

fstream& operator<< (fstream& fstr, const radar_param::mode& mod)
{
    fstr << "INSERT INTO radar_modes ("
         << " mode_no , range_max , rotation_speed , elevation_max"
         << ", potential_flag , power_potential , pulse_power"
         << ", time_bandwidth , sensibility , radar_name)" << endl;
    fstr << "VALUES ("
         << mod.mode_no << " , " << mod.range_max << " , "
         << mod.rotation_speed << " , " << mod.elevation_max << " , " << mod.potential_flag << " , "
         << mod.power_potential << " , " <<  mod.pulse_power << " , " << mod.time_bandwidth << " , "
         << mod.sensibility << " , ";

    return fstr;
}

ostream& operator<< (ostream& os, const radar_param& param)
{
    os << "name = " <<  param.name << endl;
    os << "type_of_targets = " <<  param.type_of_targets << endl;
    os << "time_off_ready_cmmn = " <<  param.time_off_ready_cmmn << endl;
    os << "time_off_ready_accel = " <<  param.time_off_ready_accel << endl;
    os << "time_prepare_radtn = " <<  param.time_prepare_radtn << endl;
    os << "cont_work_time = " <<  param.cont_work_time << endl;
    os << "frequency_band = " <<  param.frequency_band << endl;
    os << "path_efficiency = " <<  param.path_efficiency << endl;
    os << "wave_length = " <<  param.wave_length << endl;
    os << "ant_gain_factor = " <<  param.ant_gain_factor << endl;
    os << "ant_side_lobe_level = " <<  param.ant_side_lobe_level << endl;
    os << "lobe_side_orient = " <<  param.lobe_side_orient << endl;
    os << "noise_ratio = " <<  param.noise_ratio << endl;
    os << "blind_zone = " <<  param.blind_zone << endl;
    os << "targets_qty = " <<  param.targets_qty << endl;
    os << "scans_qty = " <<  param.scans_qty << endl;
    os << "operators_qty = " <<  param.operators_qty << endl;
    os << "targets_op_qty = " <<  param.targets_op_qty << endl;
    os << "bearing_rmse = " <<  param.bearing_rmse << endl;
    os << "range_rmse = " <<  param.range_rmse << endl;
    os << "elev_rmse = " <<  param.elev_rmse << endl;
    os << "speed_rmse = " <<  param.speed_rmse << endl;
    os << "course_rmse = " <<  param.course_rmse << endl;

    for (
        vector<radar_param::mode>::const_iterator it = param.modes.begin()
      , last = param.modes.end()
      ; it != last
      ; ++it
      )
    {
        os << *it;
    }

    return  os;
}

fstream& operator<< (fstream& fstr, const radar_param& param)
{
    fstr << "INSERT INTO radars ("
         << " radar_name , type_of_targets , time_off_ready_cmmn , time_off_ready_accel, time_prepare_radtn"
         << ", cont_work_time , frequency_band , path_efficiency , wave_length , ant_gain_factor , ant_side_lobe_level"
         << ", lobe_side_orient , noise_ratio , blind_zone, targets_qty, scans_qty, operators_qty, targets_op_qty"
         << ", bearing_rmse, range_rmse, elev_rmse, speed_rmse, course_rmse)" << endl;
    fstr << "VALUES ("
         << "'" << param.name << "'" << " , " << param.type_of_targets << " , " << param.time_off_ready_cmmn << " , "
         << param.time_off_ready_accel << " , " << param.time_prepare_radtn << " , " << param.cont_work_time << " , "
         << param.frequency_band << " , " <<  param.path_efficiency << " , " << param.wave_length << " , "
         << param.ant_gain_factor << " , " <<  param.ant_side_lobe_level << " , " << param.lobe_side_orient << " , "
         << param.noise_ratio << " , " <<  param.blind_zone << " , " << param.targets_qty << " , "
         << param.scans_qty << " , " <<  param.operators_qty << " , " << param.targets_op_qty << " , "
         << param.bearing_rmse << " , " <<  param.range_rmse << " , " << param.elev_rmse << " , "
         << param.speed_rmse << " , " <<  param.course_rmse << ");" << endl;

    for (
        vector<radar_param::mode>::const_iterator it = param.modes.begin()
      , last = param.modes.end()
      ; it != last
      ; ++it
      )
    {
        fstr << *it << "'" << param.name << "'" << ");" << endl;
    }

    fstr << endl << endl;

    return  fstr;
}

radar_param make_param(const string radar_name, const int type_of_targets, int count_modes)
{
    radar_param radar;

    radar.name = radar_name;
    radar.type_of_targets = type_of_targets;
    radar.modes = std::vector<radar_param::mode>(count_modes);

    return radar;
}

namespace type_of_targets
{
    const int ALL = 0;
    const int AIR = 1;
    const int SURFACE = 2;
}

BOOST_AUTO_TEST_CASE(cpc_td_generator_test)
{
    using namespace cms17;

    /// amdr3d

    radar_param r_amdr_parameters = make_param("AMDR3D", type_of_targets::AIR, 2);
    r_amdr_parameters.time_off_ready_cmmn = irs::time_off_ready_cmmn.decode(300);
    r_amdr_parameters.time_off_ready_accel = irs::time_off_ready_accel.decode(180);
    r_amdr_parameters.time_prepare_radtn = irs::time_prepare_radtn.decode(5);
    r_amdr_parameters.cont_work_time = irs::cont_work_time.decode(24);
    r_amdr_parameters.frequency_band = irs::frequency_band.decode(2);
    r_amdr_parameters.path_efficiency = irs::path_efficiency.decode(60);
    r_amdr_parameters.wave_length = irs::wave_length.decode(100);
    r_amdr_parameters.ant_gain_factor = irs::ant_gain_factor.decode(2000);
    r_amdr_parameters.ant_side_lobe_level = irs::ant_side_lobe_level.decode(-2500);
    r_amdr_parameters.lobe_side_orient = 1.0 * M_PI / 180.0;
    r_amdr_parameters.noise_ratio = irs::noise_ratio.decode(300);
    r_amdr_parameters.blind_zone = irs::blind_zone.decode(1500);
    r_amdr_parameters.targets_qty = irs::targets_qty.decode(100);
    r_amdr_parameters.scans_qty = irs::scans_qty.decode(3);
    r_amdr_parameters.operators_qty = irs::operators_qty.decode(1);
    r_amdr_parameters.targets_op_qty = irs::targets_op_qty.decode(4);
    r_amdr_parameters.bearing_rmse = irs::bearing_rmse.decode(54);
    r_amdr_parameters.range_rmse = irs::range_rmse.decode(100);
    r_amdr_parameters.elev_rmse = irs::elev_rmse.decode(65);
    r_amdr_parameters.speed_rmse = irs::speed_rmse.decode(100);
    r_amdr_parameters.course_rmse = irs::course_rmse.decode(1274);
    r_amdr_parameters.modes[0].mode_no = irs::mode_no.decode(1);
    r_amdr_parameters.modes[0].range_max = 150000.0;
    r_amdr_parameters.modes[0].rotation_speed = (160.0 * M_PI_180);
    r_amdr_parameters.modes[0].elevation_max = (60.0 * M_PI_180);
    r_amdr_parameters.modes[0].potential_flag = irs::potential_flag.decode(1);
    r_amdr_parameters.modes[0].power_potential = irs::power_potential.decode(186);
    r_amdr_parameters.modes[0].pulse_power = irs::pulse_power.decode(1000000);
    r_amdr_parameters.modes[0].time_bandwidth = irs::time_bandwidth.decode(1);
    r_amdr_parameters.modes[0].sensibility = irs::sensibility.decode(-130);
    r_amdr_parameters.modes[1].mode_no = irs::mode_no.decode(2);
    r_amdr_parameters.modes[1].range_max = 150000.0;
    r_amdr_parameters.modes[1].rotation_speed = (72.0 * M_PI_180);
    r_amdr_parameters.modes[1].elevation_max = irs::elevation_max.decode(12743);
    r_amdr_parameters.modes[1].potential_flag = irs::potential_flag.decode(1);
    r_amdr_parameters.modes[1].power_potential = irs::power_potential.decode(186);
    r_amdr_parameters.modes[1].pulse_power = irs::pulse_power.decode(1000000);
    r_amdr_parameters.modes[1].time_bandwidth = irs::time_bandwidth.decode(1);
    r_amdr_parameters.modes[1].sensibility = irs::sensibility.decode(-130);

    cout << r_amdr_parameters;

    /// amdr3der

    radar_param r_amdr3der_parameters = make_param("AMDR3DER", type_of_targets::AIR, 2);
    r_amdr3der_parameters.time_off_ready_cmmn = irs::time_off_ready_cmmn.decode(300);
    r_amdr3der_parameters.time_off_ready_accel = irs::time_off_ready_accel.decode(180);
    r_amdr3der_parameters.time_prepare_radtn = irs::time_prepare_radtn.decode(5);
    r_amdr3der_parameters.cont_work_time = irs::cont_work_time.decode(24);
    r_amdr3der_parameters.frequency_band = irs::frequency_band.decode(2);
    r_amdr3der_parameters.path_efficiency = irs::path_efficiency.decode(60);
    r_amdr3der_parameters.wave_length = irs::wave_length.decode(100);
    r_amdr3der_parameters.ant_gain_factor = irs::ant_gain_factor.decode(4000);
    r_amdr3der_parameters.ant_side_lobe_level = irs::ant_side_lobe_level.decode(-2500);
    r_amdr3der_parameters.lobe_side_orient = (1.0 * M_PI / 180.0);
    r_amdr3der_parameters.noise_ratio = irs::noise_ratio.decode(300);
    r_amdr3der_parameters.blind_zone = irs::blind_zone.decode(1500);
    r_amdr3der_parameters.targets_qty = irs::targets_qty.decode(100);
    r_amdr3der_parameters.scans_qty = irs::scans_qty.decode(3);
    r_amdr3der_parameters.operators_qty = irs::operators_qty.decode(1);
    r_amdr3der_parameters.targets_op_qty = irs::targets_op_qty.decode(4);
    r_amdr3der_parameters.bearing_rmse = irs::bearing_rmse.decode(54);
    r_amdr3der_parameters.range_rmse = irs::range_rmse.decode(100);
    r_amdr3der_parameters.elev_rmse = irs::elev_rmse.decode(65);
    r_amdr3der_parameters.speed_rmse = irs::speed_rmse.decode(100);
    r_amdr3der_parameters.course_rmse = irs::course_rmse.decode(1274);
    r_amdr3der_parameters.modes[0].mode_no = irs::mode_no.decode(1);
    r_amdr3der_parameters.modes[0].range_max = irs::range_max.decode(250000.0);
    r_amdr3der_parameters.modes[0].rotation_speed = (160.0 * M_PI_180);
    r_amdr3der_parameters.modes[0].elevation_max = irs::elevation_max.decode(12743);
    r_amdr3der_parameters.modes[0].potential_flag = irs::potential_flag.decode(1);
    r_amdr3der_parameters.modes[0].power_potential = irs::power_potential.decode(190);
    r_amdr3der_parameters.modes[0].pulse_power = irs::pulse_power.decode(100000000);
    r_amdr3der_parameters.modes[0].time_bandwidth = irs::time_bandwidth.decode(1);
    r_amdr3der_parameters.modes[0].sensibility = irs::sensibility.decode(-130);
    r_amdr3der_parameters.modes[1].mode_no = irs::mode_no.decode(2);
    r_amdr3der_parameters.modes[1].range_max = (250000.0);
    r_amdr3der_parameters.modes[1].rotation_speed = (72.0 * M_PI_180);
    r_amdr3der_parameters.modes[1].elevation_max = irs::elevation_max.decode(12743);
    r_amdr3der_parameters.modes[1].potential_flag = irs::potential_flag.decode(1);
    r_amdr3der_parameters.modes[1].power_potential = irs::power_potential.decode(190);
    r_amdr3der_parameters.modes[1].pulse_power = irs::pulse_power.decode(200000000);
    r_amdr3der_parameters.modes[1].time_bandwidth = irs::time_bandwidth.decode(1);
    r_amdr3der_parameters.modes[1].sensibility = irs::sensibility.decode(-130);

    cout << r_amdr_parameters;

    /// fregat

    radar_param r_fregatm2em_parameters = make_param("FREGATM2EM", type_of_targets::ALL, 2);
    r_fregatm2em_parameters.time_off_ready_cmmn = irs::time_off_ready_cmmn.decode(300);
    r_fregatm2em_parameters.time_off_ready_accel = irs::time_off_ready_accel.decode(210);
    r_fregatm2em_parameters.time_prepare_radtn = irs::time_prepare_radtn.decode(5);
    r_fregatm2em_parameters.cont_work_time = irs::cont_work_time.decode(24);
    r_fregatm2em_parameters.frequency_band = irs::frequency_band.decode(2);
    r_fregatm2em_parameters.path_efficiency = irs::path_efficiency.decode(60);
    r_fregatm2em_parameters.wave_length = irs::wave_length.decode(140);
    r_fregatm2em_parameters.ant_gain_factor = irs::ant_gain_factor.decode(4000);
    r_fregatm2em_parameters.ant_side_lobe_level = irs::ant_side_lobe_level.decode(-2500);
    r_fregatm2em_parameters.lobe_side_orient = (1.0 * M_PI / 180.0);
    r_fregatm2em_parameters.noise_ratio = irs::noise_ratio.decode(400);
    r_fregatm2em_parameters.blind_zone = irs::blind_zone.decode(2);
    r_fregatm2em_parameters.targets_qty = irs::targets_qty.decode(40);
    r_fregatm2em_parameters.scans_qty = irs::scans_qty.decode(3);
    r_fregatm2em_parameters.operators_qty = irs::operators_qty.decode(2);
    r_fregatm2em_parameters.targets_op_qty = irs::targets_op_qty.decode(4);
    r_fregatm2em_parameters.bearing_rmse = irs::bearing_rmse.decode(72);
    r_fregatm2em_parameters.range_rmse = irs::range_rmse.decode(120);
    r_fregatm2em_parameters.elev_rmse = irs::elev_rmse.decode(91);
    r_fregatm2em_parameters.speed_rmse = irs::speed_rmse.decode(100);
    r_fregatm2em_parameters.course_rmse = irs::course_rmse.decode(2730);
    r_fregatm2em_parameters.modes[0].mode_no = irs::mode_no.decode(1);
    r_fregatm2em_parameters.modes[0].range_max = irs::range_max.decode(300000.0);
    r_fregatm2em_parameters.modes[0].rotation_speed = 72.0 * M_PI / 180.0;
    r_fregatm2em_parameters.modes[0].elevation_max = irs::elevation_max.decode(8192);
    r_fregatm2em_parameters.modes[0].potential_flag = irs::potential_flag.decode(1);
    r_fregatm2em_parameters.modes[0].power_potential = irs::power_potential.decode(207);
    r_fregatm2em_parameters.modes[0].pulse_power = irs::pulse_power.decode(200000000);
    r_fregatm2em_parameters.modes[0].time_bandwidth = irs::time_bandwidth.decode(1);
    r_fregatm2em_parameters.modes[0].sensibility = irs::sensibility.decode(-130);
    r_fregatm2em_parameters.modes[1].mode_no = irs::mode_no.decode(2);
    r_fregatm2em_parameters.modes[1].range_max = irs::range_max.decode(300000.0);
    r_fregatm2em_parameters.modes[1].rotation_speed = 36.0 * M_PI / 180.0;
    r_fregatm2em_parameters.modes[1].elevation_max = irs::elevation_max.decode(10012);
    r_fregatm2em_parameters.modes[1].potential_flag = irs::potential_flag.decode(1);
    r_fregatm2em_parameters.modes[1].power_potential = irs::power_potential.decode(160);
    r_fregatm2em_parameters.modes[1].pulse_power = irs::pulse_power.decode(200000000);
    r_fregatm2em_parameters.modes[1].time_bandwidth = irs::time_bandwidth.decode(1);
    r_fregatm2em_parameters.modes[1].sensibility = irs::sensibility.decode(-130);

    cout << r_fregatm2em_parameters;

    fstream filestr;

    filestr.open ("radars_data.sql", fstream::in | fstream::out | fstream::app);

    filestr << r_amdr_parameters;
    filestr << r_amdr3der_parameters;
    filestr << r_fregatm2em_parameters;

    filestr.close();
}
