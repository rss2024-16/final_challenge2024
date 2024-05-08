from setuptools import setup
import glob
import os

package_name = 'final_challenge'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/final_challenge/launch', glob.glob(os.path.join('launch', '*launch.xml')))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='racecar',
    maintainer_email='P_J_Johnson@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'stop_detector = final_challenge.stop_detector.stop_detector:main',
            'parking_controller = final_challenge.stop_commands.parking_controller:main',
            'parking_controller_stoplight = final_challenge.stop_commands.parking_controller_stoplight:main',
            'parking_controller_stopsign = final_challenge.stop_commands.parking_controller_stopsign:main'
            'safety_controller = final_challenge.stop_commands.safety_controller:main',
            'stop_light_detector = final_challenge.stop_detector.stop_light_detector:main',
            'homography_transformer = final_challenge.homography_transformer:main',
            'line_detector = final_challenge.line_detector:main',
            'safety_controller = final_challenge.stop_commands.safety_controller:main',
            'basement_point_publisher = final_challenge.luigi.basement_point_publisher:main',
            'trajectory_planner = final_challenge.luigi.trajectory_planner:main',
            'integration = final_challenge.luigi.integration:main',
            'navigation_server = final_challenge.luigi.navigation_server:main',
            'path_plan_server = final_challenge.luigi.path_plan_server:main',
            'particle_filter = final_challenge.luigi.particle_filter:main',
            'fake_image_pub = final_challenge.fakepublish:main',
            'BasementPointPub = final_challenge.basement_point_publisher:main',
            'lane_projection = final_challenge.luigi.lane_projection:main',
            'example_service = final_challenge.luigi.example_service:main',
        ],
    },
)
