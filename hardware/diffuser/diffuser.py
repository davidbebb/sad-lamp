# Defuser to fit standard trunking.

max_length = 495
end_length = 10
max_width = 17
end_width = 14

origin = V(0, 0)
thickness = 3

bolt_hole_diameter = 4.5

plane = camcam.add_plane(Plane('xy', cutter='laser'))

plane.add_layer('layer_name', 'perspex', thickness)


x_max = max_length/2
y_max = max_width/2
x_min = (max_length/2) - end_length
y_min = end_width /2

bolt_hole_offset = V((max_length/2)-(end_length/2),0)

point_1 = origin+V(x_min, y_max)
point_2 = origin+V(x_min, y_min)
point_3 = origin+V(x_max, y_min)

point_4 = origin+V(x_max, -y_min)
point_5 = origin+V(x_min, -y_min)
point_6 = origin+V(x_min, -y_max)

point_7 = origin+V(-x_min, -y_max)
point_8 = origin+V(-x_min, -y_min)
point_9 = origin+V(-x_max, -y_min)

point_10 = origin+V(-x_max, y_min)
point_11 = origin+V(-x_min, y_min)
point_12 = origin+V(-x_min, y_max)

end_radius = 1
mid_radius = 0.5
border = Path(closed=True, side='out')

border.add_point(PIncurve(point_1, radius=mid_radius, direction='cw'))
border.add_point(PIncurve(point_2, radius=0, direction='cw'))
border.add_point(PIncurve(point_3, radius=end_radius, direction='cw'))
border.add_point(PIncurve(point_4, radius=end_radius, direction='cw'))
border.add_point(PIncurve(point_5, radius=0, direction='cw'))
border.add_point(PIncurve(point_6, radius=mid_radius, direction='cw'))
border.add_point(PIncurve(point_7, radius=mid_radius, direction='cw'))
border.add_point(PIncurve(point_8, radius=0, direction='cw'))
border.add_point(PIncurve(point_9, radius=end_radius, direction='cw'))
border.add_point(PIncurve(point_10, radius=end_radius, direction='cw'))
border.add_point(PIncurve(point_11, radius=0, direction='cw'))
border.add_point(PIncurve(point_12, radius=mid_radius, direction='cw'))



diffuser_part = Part(name='diffuser',
                    layer='layer_name',
                    ignore_border=False,
                    border=border)

diffuser = plane.add(diffuser_part)

diffuser.add(Hole(origin+bolt_hole_offset, bolt_hole_diameter/2))
diffuser.add(Hole(origin-bolt_hole_offset, bolt_hole_diameter/2))
