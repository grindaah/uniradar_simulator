CREATE TABLE radars (radar_name varchar(30) primary key not null unique, type_of_targets integer, time_off_ready_cmmn integer, time_off_ready_accel integer, time_prepare_radtn integer, cont_work_time integer, frequency_band integer, path_efficiency real, wave_length real, ant_gain_factor integer, ant_side_lobe_level real, lobe_side_orient real, noise_ratio real, blind_zone real, targets_qty integer, scans_qty integer, operators_qty integer, targets_op_qty integer, bearing_rmse real, range_rmse real, elev_rmse real, speed_rmse real, course_rmse real);

CREATE TABLE radar_modes (mode_no integer, range_max real, rotation_speed real, elevation_max real, potential_flag integer, power_potential real, pulse_power real, time_bandwidth integer, sensibility real, radar_name varchar(30) not null, FOREIGN KEY(radar_name) REFERENCES radars(radar_name) );