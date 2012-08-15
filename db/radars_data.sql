INSERT INTO radars ( radar_name , type_of_targets , time_off_ready_cmmn , time_off_ready_accel, time_prepare_radtn, cont_work_time , frequency_band , path_efficiency , wave_length , ant_gain_factor , ant_side_lobe_level, lobe_side_orient , noise_ratio , blind_zone, targets_qty, scans_qty, operators_qty, targets_op_qty, bearing_rmse, range_rmse, elev_rmse, speed_rmse, course_rmse)
VALUES ('AMDR3D' , 1 , 300 , 180 , 5 , 24 , 2 , 0.6 , 0.1 , 2000 , -25 , 0.0174533 , 3 , 1500 , 100 , 3 , 1 , 4 , 0.00517734 , 100 , 0.00623199 , 10 , 0.122147);
INSERT INTO radar_modes ( mode_no , range_max , rotation_speed , elevation_max, potential_flag , power_potential , pulse_power, time_bandwidth , sensibility , radar_name)
VALUES (1 , 150000 , 2.79253 , 1.0472 , 1 , 186 , 1e+06 , 1 , -130 , 'AMDR3D');
INSERT INTO radar_modes ( mode_no , range_max , rotation_speed , elevation_max, potential_flag , power_potential , pulse_power, time_bandwidth , sensibility , radar_name)
VALUES (2 , 150000 , 1.25664 , 1.22176 , 1 , 186 , 1e+06 , 1 , -130 , 'AMDR3D');


INSERT INTO radars ( radar_name , type_of_targets , time_off_ready_cmmn , time_off_ready_accel, time_prepare_radtn, cont_work_time , frequency_band , path_efficiency , wave_length , ant_gain_factor , ant_side_lobe_level, lobe_side_orient , noise_ratio , blind_zone, targets_qty, scans_qty, operators_qty, targets_op_qty, bearing_rmse, range_rmse, elev_rmse, speed_rmse, course_rmse)
VALUES ('AMDR3DER' , 1 , 300 , 180 , 5 , 24 , 2 , 0.6 , 0.1 , 4000 , -25 , 0.0174533 , 3 , 1500 , 100 , 3 , 1 , 4 , 0.00517734 , 100 , 0.00623199 , 10 , 0.122147);
INSERT INTO radar_modes ( mode_no , range_max , rotation_speed , elevation_max, potential_flag , power_potential , pulse_power, time_bandwidth , sensibility , radar_name)
VALUES (1 , 6.5535e+06 , 2.79253 , 1.22176 , 1 , 190 , 1e+08 , 1 , -130 , 'AMDR3DER');
INSERT INTO radar_modes ( mode_no , range_max , rotation_speed , elevation_max, potential_flag , power_potential , pulse_power, time_bandwidth , sensibility , radar_name)
VALUES (2 , 250000 , 1.25664 , 1.22176 , 1 , 190 , 2e+08 , 1 , -130 , 'AMDR3DER');


INSERT INTO radars ( radar_name , type_of_targets , time_off_ready_cmmn , time_off_ready_accel, time_prepare_radtn, cont_work_time , frequency_band , path_efficiency , wave_length , ant_gain_factor , ant_side_lobe_level, lobe_side_orient , noise_ratio , blind_zone, targets_qty, scans_qty, operators_qty, targets_op_qty, bearing_rmse, range_rmse, elev_rmse, speed_rmse, course_rmse)
VALUES ('FREGATM2EM' , 0 , 300 , 210 , 5 , 24 , 2 , 0.6 , 0.14 , 4000 , -25 , 0.0174533 , 4 , 2 , 40 , 3 , 2 , 4 , 0.00690312 , 120 , 0.00872478 , 10 , 0.261743);
INSERT INTO radar_modes ( mode_no , range_max , rotation_speed , elevation_max, potential_flag , power_potential , pulse_power, time_bandwidth , sensibility , radar_name)
VALUES (1 , 6.5535e+06 , 1.25664 , 0.785422 , 1 , 207 , 2e+08 , 1 , -130 , 'FREGATM2EM');
INSERT INTO radar_modes ( mode_no , range_max , rotation_speed , elevation_max, potential_flag , power_potential , pulse_power, time_bandwidth , sensibility , radar_name)
VALUES (2 , 6.5535e+06 , 0.628319 , 0.959918 , 1 , 160 , 2e+08 , 1 , -130 , 'FREGATM2EM');


